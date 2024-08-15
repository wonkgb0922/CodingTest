#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string a, b, c;
	int ai = 0, bi = 0, ci = 0;
	int d = 0;
	cin >> a >> b >> c;
	if (a[0] > '0' && a[0] <= '9')
		ai = stoi(a);
	if (b[0] > '0' && b[0] <= '9')
		bi = stoi(b);
	if (c[0] > '0' && c[0] <= '9')
		ci = stoi(c);

	if (ai) d = ai + 3;
	else if (bi) d = bi + 2;
	else if (ci) d = ci + 1;
	if (!(d % 3) && !(d % 5)) printf("FizzBuzz");
	else if (!(d % 3)) printf("Fizz");
	else if (!(d % 5)) printf("Buzz");
	else printf("%d", d);
    
	return 0;
}