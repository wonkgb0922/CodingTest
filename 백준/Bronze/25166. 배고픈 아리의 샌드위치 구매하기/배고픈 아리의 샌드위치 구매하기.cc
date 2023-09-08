#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int a, b;

	cin >> a >> b;
	if (a < 1024) printf("No thanks");
	else {
		a -= 1023;
		for (int i = 0; i < 11; i++) {
			if (1 << i & a) {
				if (!(1 << i & b)) {
					printf("Impossible");
					return 0;
				}
			}
		}
		printf("Thanks");
	}
}