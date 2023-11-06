#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <memory.h>

using namespace std;

int p[200000];

int find(int n) {
	if (p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[a] += p[b];
	p[b] = a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, cnt;
	string in, in2;
	unordered_map<string, int> m;
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n;
		memset(p, -1, sizeof(int)* 200000);
		m = unordered_map<string, int>();
		for (int i = 0; i < n; i++) {
			cin >> in >> in2;
			if (m.find(in) == m.end()) {
				m.insert({ in, cnt });
				cnt++;
			}
			if (m.find(in2) == m.end()) {
				m.insert({ in2, cnt });
				cnt++;
			}
			int val = m.find(in)->second;
			merge(m.find(in)->second, m.find(in2)->second);

			cout << -p[find(val)] << '\n';
		}
	}
	return 0;
}