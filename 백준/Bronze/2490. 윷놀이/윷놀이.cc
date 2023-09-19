#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int in, cnt;
	for (int i = 0; i < 3; i++) {
		cnt = 0;
		for (int j = 0; j < 4; j++) {
			scanf("%d", &in);
			if (!in) cnt++;
		}
		if (cnt == 0) printf("E\n");
		else if (cnt == 1) printf("A\n");
		else if (cnt == 2) printf("B\n");
		else if (cnt == 3) printf("C\n");
		else printf("D\n");
	}
	return 0;
}