#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	stack<char> s;
	string in;
	int t;
	bool d = true;

	cin >> t;

	while (t--)
	{
		d = true;
		cin >> in;
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] == '(') s.push('(');
			else if(in[i] == ')')
			{
				if (!s.empty()) s.pop();
				else
				{
					d = false;
					break;
				}
			}
		}
		if (s.empty()) {
			if (d)
			{
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
		else cout << "NO\n";
		while (!s.empty()) s.pop();
	}
	return 0;
}