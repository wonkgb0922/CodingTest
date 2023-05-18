#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int T, n, m, input;

	cin >> T;
	vector<int> a, b;

	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &input);
			a.push_back(input);
		}
		sort(a.begin(), a.end());
		scanf("%d", &m);
		
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &input);
			printf("%d\n", binary_search(a.begin(), a.end(), input));
			//cout << binary_search(a.begin(), a.end(), input);
		}
		a.clear();
	}
	
	return 0;
}