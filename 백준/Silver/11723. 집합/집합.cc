#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>

int main()
{
	int s = 0, m, par;
	char in[10];
	scanf("%d", &m);
	while (m--) {
		scanf("%s", in);
		if (!strcmp(in, "add")) {
			scanf("%d", &par);
			s |= 1 << (par - 1);
		}
		else if (!strcmp(in, "remove")) {
			scanf("%d", &par);
			s &= ~(1 << (par - 1));
		}
		else if (!strcmp(in, "check")) {
			scanf("%d", &par);
			printf("%d\n", (s & (1 << (par - 1))) != 0);
		}
		else if (!strcmp(in, "toggle")) {
			scanf("%d", &par);
			s ^= 1 << (par - 1);
		}
		else if (!strcmp(in, "all")) s = 1048575;
		else s = 0;
	}
	return 0;
}