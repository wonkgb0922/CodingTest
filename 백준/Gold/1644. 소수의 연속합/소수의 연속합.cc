#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#define MAX 4000001

using namespace std;

bool isPrime[MAX];

int main()
{
	int n, i, j, cnt = 0, sum;
	cin >> n;
	memset(isPrime, 1, sizeof(isPrime));
	for (i = 2; i < MAX / 2; i++)
		for (j = 2; i * j < MAX; j++)
			isPrime[i * j] = false;

	sum = 2;
	for (i = 2, j = 2; i <= j; ) {
		if (sum < n) {
			while (!isPrime[++j]);
			sum += j;
		}
		else if (sum > n) {
			sum -= i;
			while (!isPrime[++i]);
		}
		else {
			cnt++;
			while (!isPrime[++j]);
			sum += j;
		}
	}
	cout << cnt;
	return 0;
}