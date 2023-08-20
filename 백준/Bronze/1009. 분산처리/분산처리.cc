#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
	int r, a, b, t;
	
	scanf("%d", &t);
	while (t--) {
		r = 1;
		scanf("%d %d", &a, &b);
		while (b--) {
			r *= a;
			r %= 10;
		}
		if (r != 0) printf("%d\n", r);
		else printf("10\n");
	}
	return 0;
}