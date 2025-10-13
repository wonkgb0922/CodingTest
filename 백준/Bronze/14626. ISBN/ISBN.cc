#include <stdio.h>	
#include <iostream>

using namespace std;

int w[2] = { 1, 3 };

int main() {
	string s;
	cin >> s;
	int a = 1, sum = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '*') {
			int n = s[i] - '0';
			sum += w[i % 2] * n;
		}
		else a = w[i % 2];
	}
	for (int i = 0; i < 10; i++) {
		if ((sum + i * a) % 10 == 0)
			printf("%d", i);
	}
}