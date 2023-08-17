#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l, c;
char ary[16] = {};
vector<char> v;

void dfs(int idx, int cnt, int consonant, int vowel) {
	if (cnt >= l) {
		if (consonant >= 2 && vowel >= 1) {
			for (int i = 0; i < l; i++)
				printf("%c", ary[i]);
			printf("\n");
		}
		return;
	}
	bool isVowel = false;
	for (int i = idx + 1; i < c; i++) {
		if (v[i] - 'a' == 0 || v[i] - 'a' == 4 || v[i] - 'a' == 8 ||
			v[i] - 'a' == 14 || v[i] - 'a' == 20) isVowel = true;
		else isVowel = false;
		ary[cnt] = v[i];
		dfs(i, cnt + 1, (isVowel ? consonant : consonant + 1), (isVowel ? vowel + 1 : vowel));
	}
}

int main()
{
	char in;
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> in;
		v.push_back(in);
	}
	sort(v.begin(), v.end());
	dfs(-1, 0, 0, 0);

	return 0;
}