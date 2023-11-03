#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct Pred {
	bool operator() (pair<int, int> p1, pair<int, int> p2) {
		return p1.second < p2.second;
	}
};

int main()
{
	int n, k, in, in2;
	long long res = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Pred> q;
	multiset<int> s;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &in, &in2);
		q.push({ in,in2 });
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &in);
		s.insert(in);
	}
	while (!q.empty() && !s.empty()) {
		auto& temp = q.top();
		auto iter = s.lower_bound(temp.first);
		if (iter != s.end()) {
			res += temp.second;
			s.erase(iter);
		}
		q.pop();
	}
	cout << res;

	return 0;
}