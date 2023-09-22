#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n, in;
	priority_queue<int> q;
	cin >> n;
	while (n--) {
		scanf("%d", &in);
		if (!in) {
			if (q.empty()) printf("0\n");
			else {
				printf("%d\n", q.top());
				q.pop();
			}
		}
		else q.push(in);
	}	
	return 0;
}