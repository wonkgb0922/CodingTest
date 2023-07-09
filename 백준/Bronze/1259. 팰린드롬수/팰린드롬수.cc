#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string in, in2;
	while (true) {
		cin >> in;
		if (in == "0") break;
		in2 = in;
		reverse(in2.begin(), in2.end());
		if (in2 == in) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}