#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;

int main()
{
	char ary[1000001];
	int cnt = 0, end;

	fgets(ary, 1000001, stdin);

	for (int i = 0; i < sizeof(ary); i++) {
		if (ary[i] == ' ') cnt++;
		else if (ary[i] == '\n') {
			end = i;
			break;
		}
	}
	if (ary[0] == ' ') cnt--;
	if (ary[end - 1] == ' ') cnt--;

	cout << cnt + 1;
	return 0;
}