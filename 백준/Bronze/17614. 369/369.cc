#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, cnt, res = 0, temp, ii;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cnt = 0;
		ii = i;
		temp = ii % 10;
		if (temp == 3 || temp == 6 || temp == 9)
			cnt++;
		while (ii /= 10) {
			temp = ii % 10;
			if (temp == 3 || temp == 6 || temp == 9)
				cnt++;
		}
		res += cnt;
	}
	printf("%d", res);
	return 0;
}