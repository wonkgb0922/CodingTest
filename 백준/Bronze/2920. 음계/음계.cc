#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int prev, n, res = 0;
	scanf("%d", &n);
	prev = n;
	for (int i = 0; i < 7; i++) {
		scanf("%d", &n);
		if (prev > n) res--;
		else res++;
		prev = n;
	}
	if (res == 7) printf("ascending");
	else if (res == -7) printf("descending");
	else printf("mixed");
}