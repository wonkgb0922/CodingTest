#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	stack<char> st;
	int n, cnt = 0;
	string in;
	cin >> n;
	while (n--)
	{
		cin >> in;
		for (auto& x : in)
		{
			if (st.empty()) st.push(x);
			else
			{
				if (x == st.top()) st.pop();
				else st.push(x);
			}
		}
		if (st.empty()) cnt++;
		while (!st.empty()) st.pop();
	}
	cout << cnt;
	return 0;
}