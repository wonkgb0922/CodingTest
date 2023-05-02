#include <stdio.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
	int n;
	string input;
	int dic[26] = { 0 };
	int cal, value = 9;
	int res = 0, len = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		len = input.length();
		
		for (int j = 0; j < len; j++)
		{
			cal = 1;
			for (int k = 0; k < len - j - 1; k++) cal *= 10;
			dic[input[j] - 65] += cal;
		}
	}
	sort(dic, dic + 26, greater<int>());
	for (int i = 0; i < 26; i++)
	{
		res += value * dic[i];
		value--;
		if (dic[i] == 0) break;
	}
	cout << res;

	return 0;
}
	