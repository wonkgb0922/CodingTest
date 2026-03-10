#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	int ia = stoi(a), ib = stoi(b), ic = stoi(c);
	cout << ia + ib - ic << '\n';
	a = a + b;
	ia = stoi(a);
	cout << ia - ic;
	return 0;
}