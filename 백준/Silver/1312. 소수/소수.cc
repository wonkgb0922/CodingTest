#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	int a, b, n, res;
	cin >> a >> b >> n;
	if (a / b > 0) a %= b;
	while (n--) {
		a *= 10;
		res = a / b;
		a %= b;
	}
	cout << res;
	return 0;
}