#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<string,greater<string>> v;

int main(void)
{
	int n;
	string in, in2;
	
	scanf("%d", &n);

	while (n--) {
		cin >> in >> in2;
		if (in2 == "enter") v.insert(in);
		else v.erase(in);
	}
	for (auto& it : v)
		cout << it << '\n';
	return 0;
}