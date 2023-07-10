#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int ary[100][100] = { 0, };
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &ary[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				if (ary[j][i] + ary[i][k] > 1) ary[j][k] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", ary[i][j]);
		printf("\n");
	}

	return 0;
}