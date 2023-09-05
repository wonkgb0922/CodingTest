#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

bool enabled(const string& str)
{
	stack<char> s;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (!s.empty() && s.top() == '(')
				s.pop();
			else return false;
		}
		else if (str[i] == ']') {
			if (!s.empty() && s.top() == '[')
				s.pop();
			else return false;
		}
	}
	return s.empty();
}

int main()
{
	string str;
	stack<int> s;
	int sum = 0;
	cin >> str;

	if (enabled(str)) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(')
				s.push(-1);
			else if (str[i] == '[')
				s.push(-2);
			else if (str[i] == ')') {
				int temp = 0;

				while (!s.empty() && (s.top() > 0)) {
					temp += s.top();
					s.pop();
				}
				if (temp == 0)
					temp = 2;
				else
					temp *= 2;
				if(!s.empty()) s.pop();
				s.push(temp);
			}
			else if (str[i] == ']')
			{
				int temp = 0;

				while (!s.empty() && (s.top() > 0)) {
					temp += s.top();
					s.pop();
				}
				if (temp == 0)
					temp = 3;
				else
					temp *= 3;
				if (!s.empty()) s.pop();
				s.push(temp);
			}
		}
		while (!s.empty()) {
			sum += s.top();
			s.pop();
		}
		cout << sum;
	}
	else cout << 0;

	return 0;
}

