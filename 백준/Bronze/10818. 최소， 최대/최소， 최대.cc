#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main(void) {
	int n, input;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	printf("%d %d", v[0], v[n - 1]);
	return 0;
}
