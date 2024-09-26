#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	long n;
	cin >> n;
	if (n == 1) cout << "0\n2";
	else
		cout << n * (n - 1) / 2 << "\n2";
    
	return 0;
}