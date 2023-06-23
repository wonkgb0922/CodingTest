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
	cin >> in;
	for (int i = 0; i < in.length(); i++)
	{
		if (in[i] == '*' || in[i] == '/')
		{
			while (!s.empty())
			{
				if (s.top() == '(' || s.top() == '+' || s.top() == '-') break;
				cout << s.top();
				s.pop();
			}
			s.push(in[i]);
		}
		else if (in[i] == '+' || in[i] == '-')
		{
			while (!s.empty())
			{
				if (s.top() == '(') break;
				cout << s.top();
				s.pop();
			}
			s.push(in[i]);
		}
		else if (in[i] == '(') s.push(in[i]);
		else if (in[i] == ')')
		{
			while (!s.empty())
			{
				if (s.top() == '(')
				{
					s.pop();
					break;
				}
				cout << s.top();
				s.pop();
			}
		}
		else cout << in[i];
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}