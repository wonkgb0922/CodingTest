#include <iostream>

using namespace std;


int d[12] = { 0 };

int solve(int n)
{
	if (n < 0) return 0;
	else if (n == 0) return 1;
	if (d[n] != 0) return d[n];
	d[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
	return d[n];
}

int main(void)
{
	int t;
	int input;
	int answer[11];

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> input;
		answer[i] = solve(input);
	}
	
	for (int i = 0; i < t; i++)
	{
		cout << answer[i] << endl;
	}
}