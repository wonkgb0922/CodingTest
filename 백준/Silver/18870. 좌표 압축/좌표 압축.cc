/*
	1181번
	단어 정렬
*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main(void)
{
	int n;
	int input;
	vector<int> v;
	map<int, int> s; // sort
	int cnt = 0, temp;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v.push_back(input);
		s.insert({ input, 0 });
	}

	// cnt = 0;
	for (auto& i : s)
	{
		if (i.first == s.begin()->first)
		{
			i.second = cnt;
			temp = i.first;
		}
		else
		{
			if (i.first != temp) cnt++;
			i.second = cnt;
		}
	}
	for (auto x : v)
	{
		printf("%d ", s.find(x)->second);
		//cout << s.find(x)->second << " ";
	}
	return 0;

}