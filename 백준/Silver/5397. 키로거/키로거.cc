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
	list<char>::iterator it;
	string s;
	int t, size;

	cin >> t;
	while (t--)
	{
		cin >> s;
		l.clear();
		size = s.length();
		it = l.end();
		for(int i = 0; i < size; i++)
		{
			if (s[i] == '<')
			{
				if (it != l.begin()) it--;
			}
			else if (s[i] == '>')
			{
				if (it != l.end()) it++;
			}
			else if (s[i] == '-')
			{
				if (it != l.begin())
				{
					it--;
					it = l.erase(it);
				}

			}
			else
			{
				it = l.insert(it, s[i]);
				it++;
			}
		}
		for (auto& x : l)
			printf("%c", x);
		printf("\n");
	}
	return 0;
}
