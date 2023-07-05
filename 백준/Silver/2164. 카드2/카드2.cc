#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n, temp;
	queue<int> q;

	cin >> n;

	for (int i = 1; i <= n; i++)
		q.push(i);
	while (q.size() > 1)
	{
		q.pop();
		temp = q.front();
		q.pop();
		q.push(temp);
	}
	cout << q.front();
	return 0;
}