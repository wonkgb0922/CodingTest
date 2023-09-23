#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
	int in, res1, res2, r = -1;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			scanf("%d", &in);
			if (in > r)
				r = in, res1 = i, res2 = j;
		}
	}
	printf("%d\n%d %d", r, res1, res2);
}