#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <memory.h>

using namespace std;

int main()
{
	list<char> l;
	string s;
	int m;
	char in1, in2;
	cin >> s;

	int size = s.length();
	for (int i = 0; i < size; i++)
		l.push_back(s[i]);

	list<char>::iterator it = l.end();
	cin >> m;
	while (m--)
	{
		cin >> in1;
		if (in1 == 'P')
		{
			cin >> in2;
			it = l.insert(it, in2);
			it++;
		}
		else if (in1 == 'L')
		{
			if (it != l.begin()) it--;
		}
		else if (in1 == 'D')
		{
			if (it != l.end()) it++;
		}
		else if (in1 == 'B')
		{
			if (it != l.begin())
			{
				it--;
				it = l.erase(it);				
			}
			
		}
	}
	for (auto& x : l)
		cout << x;
	return 0;
}
