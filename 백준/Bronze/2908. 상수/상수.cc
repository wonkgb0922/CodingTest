#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string in1, in2;
	cin >> in1 >> in2;
	reverse(in1.begin(), in1.end());
	reverse(in2.begin(), in2.end());
	cout << max(stoi(in1), stoi(in2));

	return 0;
}