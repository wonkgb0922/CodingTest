#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, cnt = 0;
	scanf("%d", &x);
	for (int i = 0; i < 8; i++)
		if (x & (1 << i)) cnt++;
	printf("%d", cnt);
	return 0;
}