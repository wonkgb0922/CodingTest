#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string s;
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'C') cnt += 3;
		else if (s[i] >= 'D' && s[i] <= 'F') cnt += 4;
		else if (s[i] >= 'G' && s[i] <= 'I') cnt += 5;
		else if (s[i] >= 'J' && s[i] <= 'L') cnt += 6;
		else if (s[i] >= 'M' && s[i] <= 'O') cnt += 7;
		else if (s[i] >= 'P' && s[i] <= 'S') cnt += 8;
		else if (s[i] >= 'T' && s[i] <= 'V') cnt += 9;
		else if (s[i] >= 'W' && s[i] <= 'Z') cnt += 10;
	}
	cout << cnt;

	return 0;
}