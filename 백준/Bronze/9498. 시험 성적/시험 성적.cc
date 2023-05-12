#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	int n;
    scanf("%d%d", &n);
    if(n >= 90) printf("A");
    else if(n >= 80) printf("B");
    else if(n >= 70) printf("C");
    else if(n >= 60) printf("D");
    else printf("F");
	return 0;
}
