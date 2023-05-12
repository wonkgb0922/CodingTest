#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
    
    if(n>0)
    {
        if(m>0) printf("1");
        else printf("4");
    }
    else
    {
        if(m>0)printf("2");
        else printf("3");
    }
	
	return 0;
}