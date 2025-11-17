#include <stdio.h>	
#include <iostream>
#include <memory.h>

using namespace std;

bool isVisited[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, cnt;
	string s;
	
	cin >> n;
	cnt = n;
	while (n--) {
		memset(isVisited, 0, sizeof(isVisited));
		cin >> s;

		char prev;
		for (auto c : s) {
			if (isVisited[c - 'a']) {
				if (prev != c) {
					cnt--;
					break;
				}
			}
			else {
				isVisited[c - 'a'] = true;
				prev = c;
			}
		}
	}
	cout << cnt;

	return 0;
}