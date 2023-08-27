#include <stdio.h>

int main()
{
	int n, m;
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == m && n == 0) break;
		printf("%d\n", n + m);
	}
	return 0;
}