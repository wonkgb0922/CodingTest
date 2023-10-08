#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;
bool impo[1000001];

int main()
{
	int n, s, in, m;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		v.push_back(in);
	}
	cin >> s;
	for (int i = 0; i < n && s;) {
		in = v[i];
		for (int j = i + 1; j < n; j++) {
			if (v[j] > in && !impo[v[j]]) {
				in = v[j];
				m = j;
			}
		}
		if (in == v[i]) {
			i++;
			memset(impo, false, sizeof(impo));
			continue;
		}
		if (m - i <= s) {
			s -= m - i;
			memset(impo, false, sizeof(impo));
			for (int j = m; j > i; j--) {
				swap(v[j], v[j - 1]);
			}
			i++;
		}
		impo[in] = true;
	}
	for (auto& it : v)
		printf("%d ", it);
	return 0;
}