#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int g;
	long long i, j, ii, jj;
	bool d = false;
	cin >> g;
	for (i = 1, j = 2; i < j;) {
		ii = i * i;
		jj = j * j;
		if (jj - ii < g)
			j++;
		else if (jj - ii > g)
			i++;
		else {
			d = true;
			printf("%d\n", j++);
		}
	}
	if (!d) printf("-1");
	return 0;
}