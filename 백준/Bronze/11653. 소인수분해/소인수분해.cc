#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int n, m;
	bool res = true;

	cin >> n;
	m = n;

	for (int i = 2; n > 1;)
	{
		if (n % i == 0)
		{
			if (m != n) cout << endl;
			cout << i;
			n /= i;
		}
		else i++;
	}
	return 0;

}