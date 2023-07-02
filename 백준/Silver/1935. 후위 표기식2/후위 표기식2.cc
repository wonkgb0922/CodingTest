#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	stack<double> s;
	double ary[27] = { 0 };
	int n;
	double res = 0, par1, par2;
	string in;

	cin >> n;
	cin >> in;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	for (int i = 0; i < in.length(); i++)
	{
		
		if (in[i] == '+')
		{
			par1 = s.top();
			s.pop();
			par2 = s.top();
			s.pop();
			s.push(par1 + par2);
		}
		else if (in[i] == '*')
		{
			par1 = s.top();
			s.pop();
			par2 = s.top();
			s.pop();
			s.push(par1 * par2);
		}
		else if (in[i] == '/')
		{
			par1 = s.top();
			s.pop();
			par2 = s.top();
			s.pop();
			s.push(par2 / par1);
		}
		else if (in[i] == '-')
		{
			par1 = s.top();
			s.pop();
			par2 = s.top();
			s.pop();
			s.push(par2 - par1);
		}
		else
		{
			s.push(ary[in[i] - 65]);
		}
	}
	printf("%.2lf", s.top());
	return 0;
}