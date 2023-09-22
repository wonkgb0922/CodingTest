#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n, in, in2, res = 0;
	priority_queue<int,deque<int>,greater<int>> q;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &in);
		q.push(in);
	}
	while (q.size() != 1) {
		in = q.top();
		q.pop();
		in2 = q.top();
		q.pop();
		res += in + in2;
		q.push(in + in2);
	}
	cout << res;
	return 0;

}