#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
	int t1, t2, temp = n, cnt = 0;
	while (true)
	{
		cnt++;
		t1 = temp / 10;
		t2 = temp % 10;
		temp = t2 * 10 + (t1 + t2) % 10;
		if (temp == n) break;
	}
	cout << cnt;
	return 0;
}