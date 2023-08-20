#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	string in, res;
	cin >> n;
	cin >> res;
	n--;
	while (n--) {
		cin >> in;
		for (int i = 0; i < in.length(); i++) {
			if (res[i] != in[i]) res[i] = '?';
		}
	}
	cout << res;
	return 0;
}