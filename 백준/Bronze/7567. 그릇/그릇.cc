#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int sum = 10;
	char prev = 0, in;
	scanf("%c", &in);
	prev = in;
	while (true) {
		scanf("%c", &in);
		if (in == '\n') break;
		if (prev == in) sum += 5;
		else sum += 10;
		prev = in;
	}
	cout << sum;

	return 0;
}