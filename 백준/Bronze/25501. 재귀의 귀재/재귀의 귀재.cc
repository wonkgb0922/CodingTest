#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

//int recursion(const char* s, int l, int r) {
//	if (l >= r) return 1;
//	else if (s[l] != s[r]) return 0;
//	else return recursion(s, l + 1, r - 1);
//}

//int isPalindrome(const char* s) {
//	return recursion(s, 0, strlen(s) - 1);
//}

// string으로 개조

int res;

int recursion(string& s, int l, int r) {
	if (l >= r)
	{
		res = l+1;
		return 1;
	}
	else if (s[l] != s[r])
	{
		res = l+1;
		return 0;
	}
	else return recursion(s, l + 1, r - 1);
}
int isPalindrome(string& s) {
	return recursion(s, 0, s.length() - 1);
}

int main(void)
{
	int t;
	string s;

	cin >> t;

	while (t > 0)
	{
		res = 0;
		cin >> s;
		printf("%d ", recursion(s, 0, s.length() - 1));
		printf("%d\n", res);
		t--;
	}

	return 0;

}