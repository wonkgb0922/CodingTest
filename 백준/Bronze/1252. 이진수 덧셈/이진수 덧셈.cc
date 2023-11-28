#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	string a, b, c;
	int carry = 0, a1, b1, c1, i;
	cin >> a >> b;
	if (a.length() < b.length()) swap(a, b);

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for (i = 0; i < a.length(); i++) {
		a1 = a[i] - '0';
		if (i < b.length()) {
			b1 = b[i] - '0';
			c1 = a1 + b1 + carry;
			if (c1 > 1) {
				carry = 1;
				c1 -= 2;
			}
			else carry = 0;
			c.push_back(c1 + '0');
		}
		else {
			c1 = a1 + carry;
			if (c1 > 1) {
				carry = 1;
				c1 -= 2;
			}
			else carry = 0;
			c.push_back(c1 + '0');
		}
	}
	if (carry) c.push_back('1');
	reverse(c.begin(), c.end());
    
	i = 0;
	while (c[i++] == '0');
	i--;
	if (i == c.length()) c = '0';
	else c.erase(0, i);
	cout << c;

	return 0;
}