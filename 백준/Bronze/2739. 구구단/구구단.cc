#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
    for(int i = 1; i <= 9; i++)
        printf("%d * %d = %d\n", n, i, n*i);
	return 0;
}