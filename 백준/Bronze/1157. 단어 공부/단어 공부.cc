#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int cnt[26] = { 0, }, max = 0;
	bool eq = false;
	char s,res;
	while (scanf("%c", &s) != '\0') {
		if (s == '\n') break;
		if (s >= 'a') s -= 32; // 모두 대문자화
		cnt[s - 65]++;
		if (cnt[s - 65] > max) {
			res = s;
			eq = false;
			max = cnt[s - 65];
		}
		else if (cnt[s - 65] == max) eq = true;
	}
	if (eq) printf("?");
	else {
		printf("%c", res);
	}


	return 0;
}