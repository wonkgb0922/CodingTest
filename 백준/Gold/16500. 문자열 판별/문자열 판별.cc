#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dp[100] = { false };
string v[101];

int main()
{
	// 16500 문자열 판별
	int n;
	string s, input;
	cin >> s;
	cin >> n;
	bool res = false;

	for (int i = 0; i < n; i++)
		cin >> v[i];
	//dp[0] = true;
	int size = s.length();
	dp[size] = true;
	for (int i = size; i >= 0; i--)
	{
		for(int j = 0; j < n; j++)
		{
			if (size < v[j].length() + i) continue;
			if (s.find(v[j], i) == i)
			{
				dp[i] = dp[i] || dp[i + v[j].length()];
			}
		}
	}
	cout << dp[0];
	return 0;
}
