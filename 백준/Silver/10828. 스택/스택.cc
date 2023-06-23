#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;
	int t;

	string in1;
	int in2;
	cin >> t;
	while (t--)
	{
		cin >> in1;
		if (in1 == "push")
		{
			cin >> in2;
			s.push(in2);
		}
		else if (in1 == "pop")
		{
			if (s.empty()) cout << -1 << endl;
			else
			{
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (in1 == "size")
			cout << s.size() << endl;
		else if (in1 == "empty")
			cout << s.empty() << endl;
		else if (in1 == "top")
		{
			if (s.empty())
				cout << -1 << endl;
			else
				cout << s.top() << endl;
		}
	}
	return 0;
}