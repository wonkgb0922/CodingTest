#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int ary[1000] = { 0, };

int main()
{
	int t, n, cnt, sum;
	double avg;
	cin >> t;
	while (t--) {
		cnt = sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", ary + i);
			sum += ary[i];
		}
		avg = (double)sum / n;
		for (int i = 0; i < n; i++)
			if (ary[i] > avg) cnt++;
		printf("%.3lf%c\n", (double)cnt / n * 100, '%');
	}
}