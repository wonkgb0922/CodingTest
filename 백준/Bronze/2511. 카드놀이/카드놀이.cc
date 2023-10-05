#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int ary[10], in;
	int a(0), b(0);
	char res = 'D';
	for (int i = 0; i < 10; i++)
		scanf("%d", ary + i);
	for (int i = 0; i < 10; i++) {
		scanf("%d", &in);
		if (ary[i] > in) {
			a += 3;
			res = 'A';
		}
		else if (ary[i] < in) {
			b += 3;
			res = 'B';
		}
		else {
			a++;
			b++;
		}
	}
	printf("%d %d\n", a, b);
	if (a > b) res = 'A';
	else if (a < b) res = 'B';
	printf("%c", res);
	return 0;
}