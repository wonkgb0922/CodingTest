#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	string s;
	vector<string> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		reverse(s.begin(), s.end());
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (auto& it : v) cout << it << '\n';
	
	return 0;
}