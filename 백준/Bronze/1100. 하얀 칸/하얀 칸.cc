#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int cnt = 0;
	char in;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%c", &in);
			if (in == 'F') {
				if (i % 2 == j % 2) cnt++;
			}
		}
		getchar();
	}
	printf("%d", cnt);
	return 0;
}