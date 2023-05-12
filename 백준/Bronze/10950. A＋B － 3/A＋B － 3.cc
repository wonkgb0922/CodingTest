#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	int t, n, m;
	scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        printf("%d\n", n+m);
    }
	return 0;
}