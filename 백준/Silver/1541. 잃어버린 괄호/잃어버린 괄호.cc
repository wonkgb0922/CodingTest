#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

#pragma warning (disable:4996)

using namespace std;

vector<string> split(string s, char c)
{
	vector<string> v;
	int stt = 0, idx;
	//cout << "split() : :" << s << " " << c << endl;

	while (1)
	{
		idx = s.find(c);
		if (idx != string::npos)
		{
			v.push_back(s.substr(stt, idx));
			s.erase(stt, idx + 1);
		}
		else
		{
			v.push_back(s);
			break;
		}
	}
	//for (auto x : v)
	//{
	//	cout << x << " ";
	//}
	//cout << "split()종료" << endl;
	return v;
}

int solve(string s)
{
	//cout << s;
	//cout << "solve(" << s << ")\n";
	vector<string> v = split(s, '-');
	//for (auto x : v)
	//{
	//	cout << x << " ";
	//}
	//cout << endl;
	if (v.size() == 1)
	{
		int cnt = 0;
		v = split(s, '+');
		for (auto& x : v)
		{
			cnt += stoi(x);
		}
		return cnt;
	}
	int res = solve(v[0]);
	for (int i = 1; i < v.size(); i++)
	{
		res -= solve(v[i]);
	}
	return res;
}

int main(void) {
	int n, input;
	string s;
	cin >> s;
	
	cout << solve(s);

	return 0;
}