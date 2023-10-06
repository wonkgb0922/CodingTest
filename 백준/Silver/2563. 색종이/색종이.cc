#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
bool ary[101][101];

int main()
{
	int n, in1, in2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &in1, &in2);
		for (int j = 0; j <= 9; j++) {
			for(int k = 0; k <= 9; k++) 
				ary[in2 + j][in1 + k] = true;
		}
	}
	in1 = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++)
			if(ary[i][j]) in1++;
	}
	cout << in1;
	return 0;
}