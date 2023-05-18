#include <iostream>
#include <algorithm>
#include <set>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
	int n, input, v;
	multiset<int> s;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		s.insert(input);
	}
	cin >> v;
	cout << s.count(v);	

	return 0;
}
