#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v,temp;

int main() {
	int n, m, i, j, k;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		v.push_back(i);
	while (m--) {
		scanf("%d%d%d", &i, &j, &k);
		i--, j--, k--;
		temp.insert(temp.end(), v.begin() + k, v.begin() + j + 1);
		temp.insert(temp.end(), v.begin() + i, v.begin() + k);
		copy(temp.begin(), temp.end(), v.begin() + i);
		temp.clear();
	}	
	for (auto& it : v)
		cout << it << ' ';
	return 0;
}