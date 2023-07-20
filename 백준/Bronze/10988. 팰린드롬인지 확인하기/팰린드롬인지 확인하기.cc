#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string s, rs;
	cin >> s;
	rs = s;
	reverse(s.begin(), s.end());
	if (s == rs) cout << 1;
	else cout << 0;
	return 0;
}