#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	while (b.length()) {
		if (b.back() == 'A') b.erase(b.end() - 1);
		else {
			b.erase(b.end() - 1);
			reverse(b.begin(), b.end());
		}
		if (b == a) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}