#include <stdio.h>	
#include <iostream>

using namespace std;

int main() {


	int t, n, m;
	char ary[50][50];
	bool flag;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		int cntX = 0, cntY = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> ary[i][j];
			}
			getchar();
		}
		// 가로
		for (int i = 0; i < n; i++) { 
			flag = false;
			for (int j = 0; j < m; j++) {
				if (ary[i][j] != '#') {
					flag = true;
					break;
				}
			}
			if (!flag) cntY++;
		}
		// 세로
		for (int i = 0; i < m; i++) {
			flag = false;
			for (int j = 0; j < n; j++) {
				if (ary[j][i] != '#') {
					flag = true;
					break;
				}
			}
			if (!flag) cntX++;
		}
		if (cntX == m && cntY == n)
			cout << min(cntX, cntY) << '\n';
		else
			cout << cntX + cntY << '\n';
	}

	return 0;
}