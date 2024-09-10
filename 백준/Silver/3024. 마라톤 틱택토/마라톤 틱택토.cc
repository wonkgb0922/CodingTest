#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
string in[30];

bool isHorizen(int i, int j) {
	if (j + 2 >= n) return false;
	return in[i][j] == in[i][j + 1] && in[i][j+1] == in[i][j + 2];
}

bool isVertical(int i, int j) {
	if (i + 2 >= n) return false;
	return in[i][j] == in[i + 1][j] && in[i + 1][j] == in[i + 2][j];
}
bool isLeftDiagonal(int i, int j) {
	if (i + 2 >= n || j + 2 >= n) return false;
	return (in[i][j] == in[i + 1][j + 1] && in[i + 1][j + 1] == in[i + 2][j + 2]);
}
bool isRightDiagonal(int i, int j) {
	if (i + 2 >= n || j - 2 < 0) return false;
	return (in[i][j] == in[i + 1][j - 1] && in[i + 1][j - 1] == in[i + 2][j - 2]);
}

int main()
{
	bool f = false;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> in[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (in[i][j] != '.' && (isHorizen(i, j) || isVertical(i, j) || isLeftDiagonal(i, j) || isRightDiagonal(i, j))) {
				cout << in[i][j];
				f = true;
				break;
			}
		}
		if (f) break;
	}
	if (!f) cout << "ongoing";
	return 0;
}