#include <stdio.h>
#include <iostream>

using namespace std;

int ary[10][20];

int main()
{
	
	int n, in;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c%d", &c, &in);
		ary[c - 65][in - 1] = 1;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++)
			cout << ((ary[i][j]) ? 'o' : '.');
		cout << '\n';
	}
	
	return 0;
}