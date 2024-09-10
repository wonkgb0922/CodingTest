#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	for (auto& it : s)
		it -= 32;
	cout << s;
}