#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

const int dir[] = { 3,-3 };
queue<pair<string, int>> q;
set<string> s;

int main()
{
	int in, qsize, level = -1, pos;
	string temp = "", next;
	char swap;
	bool sol = false;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &in);
		if (in == 0) pos = i;
		temp += to_string(in);
	}
	q.push({ temp , pos });
	s.insert(temp);
	while (!q.empty()) {
		qsize = q.size();
		level++;
		//printf("------------------%d %d, set의 크기 : %d\n", level, qsize, s.size());
		while (qsize--) {
			temp = q.front().first;
			pos = q.front().second;
			q.pop();
			/*for (int i = 0; i < 9; i++) {
				printf("%c ", temp[i]);
				if (i % 3 == 2) printf("\n");
			}
			printf("pos : %d, qsize : %d\n\n", pos, qsize);*/
			if (temp == "123456780") {
				sol = true;
				break;
			}
			// 오른쪽과 교환
			if (pos % 3 != 2) {
				next = temp;
				swap = next[pos];
				next[pos] = next[pos + 1];
				next[pos + 1] = swap;
				if (s.find(next) == s.end()) {
					s.insert(next);
					q.push({ next, pos + 1});
				}
			}
			// 위아래 교환
			for (int i = 0; i < 2; i++) {
				if (pos + dir[i] >= 0 && pos + dir[i] <= 8) {
					next = temp;
					swap = next[pos];
					next[pos] = next[pos + dir[i]];
					next[pos + dir[i]] = swap;
					if (s.find(next) == s.end()) {
						s.insert(next);
						q.push({ next, pos + dir[i] });
					}
				}
			}
			// 왼쪽과 교환
			if (pos % 3 != 0) {
				next = temp;
				swap = next[pos];
				next[pos] = next[pos - 1];
				next[pos - 1] = swap;
				if (s.find(next) == s.end()) {
					s.insert(next);
					q.push({ next, pos - 1 });
				}
			}
		}
		if (sol) break;
	}
	if (sol) printf("%d", level);
	else printf("-1");
	return 0;
}