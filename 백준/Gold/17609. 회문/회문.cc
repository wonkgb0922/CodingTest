#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

string s;

bool isPal(int i, int j)
{
	while (i < j) {
		if (s[i] == s[j]) {
			i++;
			j--;
		}
		else return false;
	}
	return true;
}

int main()
{
	int t, i, j, res;
	cin >> t;
	while (t--) {
		cin >> s;
		res = 0;
		for (i = 0, j = s.length() - 1; i < j;) {
			if (s[i] == s[j]) {
				i++;
				j--;
			}
			else {
				if (isPal(i + 1, j) || isPal(i, j - 1))
					res = 1;
				else 
					res = 2;
				break;
			}
		}
		cout << res << "\n";
	}
	return 0;
}