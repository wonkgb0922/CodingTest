#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	char in;
	int cnt = 0;
	for (;;) {
		scanf("%c", &in);
		if (in == '\n') break;
		if (in == 'a' || in == 'e' || in == 'i' || in == 'o' || in == 'u')
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}