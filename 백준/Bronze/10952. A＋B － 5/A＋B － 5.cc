#include <stdio.h>

int main(void)
{
	int n, m;
	while (true)
	{
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		printf("%d\n", n + m);
	}
	return 0;
}