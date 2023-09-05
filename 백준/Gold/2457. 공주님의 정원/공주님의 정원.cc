#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int ary[1232] = { 0, };

int main(void)
{
	int n;
	bool d = false;

	int fmonth, fday;
	int emonth, eday;

	int month = 3, day = 1, cnt = 0;
	int fdate = 301, edate = 1130;
	int temp = 301;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> fmonth >> fday >> emonth >> eday;
		int index = fmonth * 100 + fday;
		int value = emonth * 100 + eday;

		if (ary[index]  < value) ary[index] = value;
	}

	for (int i = 0; i < 1232; i++) {
		if (ary[i] == 0 && i < 301) continue;
		if (i == ary[i]) continue;
		if (fdate > edate) break;
		if (i <= 301) {
			if (fdate < ary[i]) {
				fdate = ary[i];
				cnt = 1;
			}
		}
		else if (i <= fdate) {
			if (temp < ary[i]) temp = ary[i];
		}
		else if (i > fdate) {
			if (temp >= fdate) {
				fdate = temp;
				cnt++;
				if (i <= fdate) {
					temp = ary[i];
				}
			}
			else break;
		}
	}
	if (fdate > edate) cout << cnt;
	else cout << 0;

	return 0;
}