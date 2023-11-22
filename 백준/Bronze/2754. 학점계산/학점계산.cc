#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	string i;
	cin >> i;
	float r;
	if (i == "A+") r = 4.3;
	else if (i == "A0") r = 4.0;
	else if (i == "A-") r = 3.7;
	else if (i == "B+") r = 3.3;
	else if (i == "B0") r = 3.0;
	else if (i == "B-") r = 2.7;
	else if (i == "C+") r = 2.3;
	else if (i == "C0") r = 2.0;
	else if (i == "C-") r = 1.7;
	else if (i == "D+") r = 1.3;
	else if (i == "D0") r = 1.0;
	else if (i == "D-") r = 0.7;
	else r = 0;
	printf("%.1f", r);
	return 0;
}