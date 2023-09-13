#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(void)
{
	int in, sum = 0;
	for (int i = 1; i <= 5; i++) {
		scanf("%d", &in);
		v.push_back(in);
		sum += in;
	}
	sort(v.begin(), v.end());
	printf("%d\n%d", sum / 5, v[2]);


	return 0;
}