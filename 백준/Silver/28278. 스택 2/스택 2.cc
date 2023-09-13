#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, in, in2;
	stack<int> s;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &in);
		if (in == 1) {
			scanf("%d", &in2);
			s.push(in2);
		}
		else if (in == 2) {
			if (!s.empty()) {
				printf("%d\n", s.top());
				s.pop();
			}
			else printf("-1\n");
		}
		else if (in == 3) printf("%d\n", s.size());
		else if (in == 4) printf("%d\n", s.empty());
		else {
			if (!s.empty()) printf("%d\n", s.top());
			else printf("-1\n");
		}
	}
	return 0;
}