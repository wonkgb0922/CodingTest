#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

#pragma warning (disable:4996)

using namespace std;

int n;
string S;
string ary[101];
int dp[101];

bool word(int k)
{
	//cout << "\n<<<word(" << k << ") 호출!!>>>\n";
	if (k == S.length()) return true;
	int &res = dp[k];

	if (res != -1) return res;
	res = 0;

	for (int i = 0; i < n; i++)
	{
		if (S.length() < ary[i].length() + k) continue;
		if (S.find(ary[i], k) == k)
		{
			//int pos = k + ary[i].length();
			//cout << k << "번에서 부터" << ary[i] << "탐색" << endl;
			res = res || word(k + ary[i].length());
		}
	}
	return res;
}

int main(void) {
		
	cin >> S;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
	}
	memset(dp, -1, sizeof(dp));
	
	cout << word(0);
	return 0;
}