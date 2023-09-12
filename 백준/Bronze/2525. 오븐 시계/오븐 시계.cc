#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int h, m, in, temp;
	cin >> h >> m;
	cin >> in;
	
	printf("%d %d", (h+(m+in)/60)%24, (m+in)%60);
	return 0;
}