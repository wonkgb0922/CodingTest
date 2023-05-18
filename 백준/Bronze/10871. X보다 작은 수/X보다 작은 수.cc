#include <iostream>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
	int n, input, x;
	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		if (input < x) printf("%d ", input);
	}

	return 0;
}
