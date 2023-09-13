#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, in, sum = 0;
	stack<int> s;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &in);
		if (in != 0)s.push(in);
		else s.pop();
	}
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	printf("%d", sum);
	return 0;
}