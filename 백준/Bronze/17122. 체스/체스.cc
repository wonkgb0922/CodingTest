#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool isWhite[65];

int main()
{
	int t, in1, in2;
	string in;

	for (int i = 1; i < 65; i++) {
		if (((i - 1) / 8) % 2) {
			if (i % 2)
				isWhite[i] = true;
		}
		else
			if (!(i % 2))isWhite[i] = true;
	}
	cin >> t;
	while (t--) {
		cin >> in >> in2;
		in1 = (in[1] - '1') * 8 + (in[0] - 'A' + 1);
		if (isWhite[in1] == isWhite[in2]) printf("YES\n");
		else printf("NO\n");
	}
	

	return 0;
}