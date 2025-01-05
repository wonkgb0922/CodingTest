#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int m, n, flag = 0, i;
	string s;

	cin >> n >> m >> s;
	i = s.length() - 1;

	while (s.length() >= m) {
		if (flag == 0) {
			if (s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U') {
				flag = 1;
			}
			else s.erase(i, 1);
		}
		else if (flag == 1 || flag == 2) {
			if (s[i] == 'A') flag++;
			else s.erase(i, 1);
		}
		else {
			if (s.length() == m) break;
			s.erase(i, 1);		
		}
		i--;
	}
	if (flag == 3) {
		cout << "YES\n" << s;
	}
	else printf("NO");

	return 0;
}