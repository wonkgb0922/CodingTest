#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

int main()
{
	int n, k, i;
	cin >> n >> k;
	vector<int> v, res;
	for (i = 0; i < n; i++)
		v.push_back(i + 1);
    
	i = 0;
	while (!v.empty())
	{
		i += (k - 1);
		i %= v.size();
		res.push_back(v[i]);
		v.erase(v.begin() + i);
	}
	printf("<");
	for (int i = 0; i < n; i++)
	{
		printf("%d", res[i]);
		if (i != n - 1) printf(", ");
	}
	printf(">");

	return 0;
}
