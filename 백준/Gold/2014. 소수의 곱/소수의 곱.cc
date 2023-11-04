#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#define MAX pow(2,31)

using namespace std;

int main()
{
	int k, n, in, cnt = 1;
	priority_queue<int, vector<int>, greater<>> q;
	vector<long long> v;
	scanf("%d%d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%d", &in);
		q.push(in);
		v.push_back(in);
	}
	in = 1;
	while (cnt <= n) {
		auto t = q.top();
		//printf("%d : %d\n", cnt, t);
		q.pop();
		if (in == t) {
			continue;
		}
		for (auto& it : v) {
			long long temp = t * it;
			if (temp >= MAX) break;
			q.push(temp);
		}
		in = t;
		cnt++;
	}
	cout << in;

	return 0;
}