#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int fibo(int n)
{
	
	if (n <= 2)
	{
		if (n <= 0) return 0;
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}

int main(void)
{
	int n;


	cin >> n;
	

	printf("%d", fibo(n));
	return 0;

}