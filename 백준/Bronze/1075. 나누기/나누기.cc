#include <stdio.h>

int main()
{
	int a, b;

	scanf("%d%d", &a, &b);
	a /= 100;
	a *= 100;
	for (int i = 0; i < 100; i++) {
		if (!((a + i) % b)) {
			printf("%02d", i);
			break;
		}
	}
	return 0;
}