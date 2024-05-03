#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string s[5], res;
	size_t n = 0;
	for (int i = 0; i < 5; i++) {
		cin >> s[i];
		n = max(n, s[i].length());
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			if(s[j].length() > i)
				res += s[j][i];
		}
	}
	cout << res;
	return 0;
}