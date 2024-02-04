#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m, in, i, j, cnt = 0;
	vector<int> v;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf("%d", &in);
		v.push_back(in);
	}
	cin >> m;
	sort(v.begin(), v.end());
	
	for (i = 0, j = n - 1; i < j;) {
		if (v[i] + v[j] == m) {
			cnt++;
			i++;
		}
		else if (v[i] + v[j] < m) i++;
		else j--;
	}
	cout << cnt;
	return 0;
}