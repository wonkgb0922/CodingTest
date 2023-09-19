#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> s;

int main() {
	int n, m, in;
	cin >> n;
	for(int i = 0; i < n; i++) {
		scanf("%d", &in);
		s.insert(in);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d", &in);
		if (s.count(in) > 0) printf("1\n");
		else printf("0\n");
	}
	return 0;
}