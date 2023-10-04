#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		int res = n;
		while (n >= k) {
			res += n / k;
			n = n / k + n%k;
		}
		printf("%d\n", res);
	}
}