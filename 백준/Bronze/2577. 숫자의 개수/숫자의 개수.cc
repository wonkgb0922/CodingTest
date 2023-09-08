#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int cnt[10] = { 0, };

int main()
{
	int a, b, c, res;
	cin >> a >> b >> c;
	res = a * b * c;
	while (res) {
		cnt[res % 10]++;
		res /= 10;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", cnt[i]);
}