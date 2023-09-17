#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int w, h;
	cin >> w >> h;
	printf("%.1lf", w * h / 2.);
	return 0;
}