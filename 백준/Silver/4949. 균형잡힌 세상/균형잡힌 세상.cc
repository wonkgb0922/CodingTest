#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
	char in[100];
	stack<char> s;

	while (1) {
		s = stack<char>();
		bool sol = true;
		gets(in);
		if (in[0] == '.') break;
		for (int i = 0; i < strlen(in); i++) {
			if (in[i] == '(' || in[i] == '[') s.push(in[i]);
			else if (in[i] == ')') {
				if (s.empty() || s.top() != '(') {
					sol = false;
					break;
				}
				else if (s.top() == '(') s.pop();
			}
			else if (in[i] == ']') {
				if (s.empty() || s.top() != '[') {
					sol = false;
					break;
				}
				else if (s.top() == '[') s.pop();
			}
		}
		if (s.empty() && sol) printf("yes\n");
		else printf("no\n");
	}
}