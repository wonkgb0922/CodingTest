#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int k;
set<int> s[8];

set<int>& sol(int n) {
	if (!s[n].empty()) return s[n];
	int temp = k, i = n;
	while (i--) {
		temp *= 10;
		temp += k;
	}
	s[n].insert(temp);
	s[n].insert(-temp);
	for (int i = 0; i < n; i++) {
		for (auto& it : sol(i)) {
			for (auto& it2 : sol(n - i - 1)) {
				s[n].insert(it + it2);
				s[n].insert(-it - it2);
				s[n].insert(it - it2);
				s[n].insert(it2 - it);
				s[n].insert(it * it2);
				if (it2 != 0) {
					s[n].insert(it / it2);
					s[n].insert(-(it / it2));
				}
				if (it != 0) {
					s[n].insert(it2 / it);
					s[n].insert(-(it2 / it));
				}
			}
		}
	}
	return s[n];
}

int main()
{
	int t, n;
	scanf("%d%d", &k, &t);
	while (t--) {
		bool d = false;
		scanf("%d", &n);
		for (int i = 0; i < 8; i++) {
			if (sol(i).find(n) != sol(i).end()) {
				printf("%d\n", i + 1);
				d = true;
				break;
			}
		}
		if (!d) printf("NO\n");
	}
	return 0;
}