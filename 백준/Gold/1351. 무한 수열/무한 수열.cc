#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int p, q;
map<long long, long long> m;

long long sol(long long n) {
	if (n == 0) return 1;
	if (m.find(n) != m.end()) return m[n];
	long long res = sol(n / p) + sol(n / q);
	m.insert({ n, res });
	return res;
}

int main()
{
	long long n;
	scanf("%lld%d%d", &n, &p, &q);

	printf("%lld", sol(n));
	
	return 0;
}