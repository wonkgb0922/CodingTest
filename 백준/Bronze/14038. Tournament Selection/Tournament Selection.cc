#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	char c;
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		cin >> c;
		getchar();
		if (c == 'W') cnt++;
	}
	if (cnt > 0) {
		if (cnt > 2) {
			if (cnt > 4) cout << 1;
			else cout << 2;
		}
		else cout << 3;
	}
	else cout << -1;
	return 0;
}