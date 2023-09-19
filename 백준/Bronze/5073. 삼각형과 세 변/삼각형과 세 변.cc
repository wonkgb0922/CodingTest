#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int ary[3];
	for (;;) {
		scanf("%d%d%d", &ary[0], &ary[1], &ary[2]);
		sort(ary, ary + 3);
		if (ary[0] == ary[1] && ary[1] == ary[2]) {
			if (ary[0] == 0) break;
			printf("Equilateral\n");
		}
		else {
			if (ary[2] >= ary[0] + ary[1]) printf("Invalid\n");
			else if (ary[0] == ary[1] || ary[0] == ary[2] || ary[1] == ary[2])
				printf("Isosceles\n");
			else printf("Scalene\n");
		}		
	}
	return 0;
}