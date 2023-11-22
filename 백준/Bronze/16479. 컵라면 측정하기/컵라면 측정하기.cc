#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	double k, d1, d2;
	cin >> k >> d1 >> d2;
	k *= k;
	if (d1 == d2) cout << k;
	else {
		d1 = (d2 - d1) / 2;
		d1 *= d1;
		cout << k - d1;
	}

	return 0;
}