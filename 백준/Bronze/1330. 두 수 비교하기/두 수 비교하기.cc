#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	int n, m;
    scanf("%d%d", &n, &m);
    if(n > m) printf(">");
    else if(n < m) printf("<");
    else printf("==");
	return 0;
}