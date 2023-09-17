#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, ary[1000], in, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", ary + i);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		if (in >= ary[i]) cnt++;
	}
	cout << cnt;
    
	return 0;
}