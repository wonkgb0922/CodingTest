#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	if ((by - ay) * (cx - ax) == (cy - ay) * (bx - ax)) {
		printf("-1.0");
		return 0;
	}
	double a[3];
	a[0] = pow(ax - bx, 2) + pow(ay - by, 2);
	a[1] = pow(ax - cx, 2) + pow(ay - cy, 2);
	a[2] = pow(bx - cx, 2) + pow(by - cy, 2);
	sort(a, a + 3);
	a[0] = sqrt(a[0]);
	a[1] = sqrt(a[1]);
	a[2] = sqrt(a[2]);
	printf("%.15f", 2 * (a[2] - a[0]));
	return 0;
}