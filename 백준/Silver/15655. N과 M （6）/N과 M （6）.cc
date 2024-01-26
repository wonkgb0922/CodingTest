#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

vector<int> v;
int res[8], n, m;
bool visited[8];


void dfs(int cnt)
{
	if (cnt >= m) {
		for (int i = 0; i < m; i++)
			printf("%d ", res[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (cnt == 0 || res[cnt - 1] < v[i]) {
				res[cnt] = v[i];
				visited[i] = true;
				dfs(cnt + 1);
				visited[i] = false;
			}
		}
	}
}

int main(void)
{
	int input;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	dfs(0);
}