#include <stdio.h>

int main()
{
	int a, b, c, d, e;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	d = (d > e) ? e : d;
	a = (a < b) ? ((a < c) ? a : c) : (b < c) ? b : c;
	printf("%d", a + d - 50);
	return 0;
}