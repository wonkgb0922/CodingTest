#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct pred {
	bool operator()(int a, int b) {
		int ma = max(a, -a);
		int mb = max(b, -b);
		if (ma == mb) return a > b;
		return ma > mb;
	}
};

int main()
{
	priority_queue<int,vector<int>,pred> q;
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