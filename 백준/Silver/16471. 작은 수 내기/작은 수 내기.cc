#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int ary[100001] = { 0, };
int ary2[100000];

int main() {
	int n, in, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		ary[in]++;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", ary2 + i);		
	}
	sort(ary2, ary2 + n, greater<int>());
	for (int i = 0; i < n; i++) {
		for (int j = ary2[i] - 1; j >= 0; j--) {
			if (ary[j] > 0) {
				ary[j]--;
				cnt++;
				break;
			}
		}
		if (cnt >= (n + 1) / 2) {
			printf("YES");
			return 0;
		}
	}	
	printf("NO");
	return 0;
}