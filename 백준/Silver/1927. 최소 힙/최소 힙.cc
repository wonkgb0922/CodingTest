#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int,vector<int>,greater<int>> q;
	int n, in;
	cin >> n;
	while (n--) {
		scanf("%d", &in);
		if (in) q.push(in);
		else {
			if (!q.empty()) {
				printf("%d\n", q.top());
				q.pop();
			}
			else printf("0\n");
		}
	}
	return 0;
}