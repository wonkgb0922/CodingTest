#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include <vector>
using namespace std;

vector<int> pos;

int main()
{
	int n, m, x, l, r, mid, cur = 0;
	bool valid;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		pos.push_back(x);
	}
	r = n;
	l = pos[0];
	while (l < r) {
		cur = pos[0];
		valid = true;
		mid = (l + r) / 2 ;
		for (int i = 1; i < m; i++) {
			if (cur + (mid*2) >= pos[i])
				cur = pos[i];
			else {
				valid = false;
				break;
			}
		}
		if (valid) {
			if (cur + mid >= n)
				r = mid;
			else l = mid + 1;
		}
		else l = mid + 1;
	}
	cout << r;
	

	return 0;
}