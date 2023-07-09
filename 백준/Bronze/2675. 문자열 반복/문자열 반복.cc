#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string in;
	int t, r;
	cin >> t;
	while (t--) {
		cin >> r >> in;
		for (int i = 0; i < in.length(); i++) {
			for (int j = 0; j < r; j++)
				printf("%c", in[i]);
		}
		printf("\n");
	}

	return 0;
}