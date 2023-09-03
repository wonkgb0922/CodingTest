#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main()
{
	char c;
	while (true) {
		scanf("%c", &c);
		if (c == '\n') break;
		if (c >= 'a' && c <= 'z') c -= 32;
		else c += 32;
		printf("%c", c);
	}

	return 0;
}