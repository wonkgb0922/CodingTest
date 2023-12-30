#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	multiset<long> mm;
	int t, k, in;
	char com;

	cin >> t;
	while (t--) {
		cin >> k;
		while (k--) {
			cin >> com >> in;
			if (com == 'I') mm.insert(in);
			else {
				if (in == -1) {
					if(!mm.empty()) mm.erase(mm.begin());
				}
				else {
					if (!mm.empty()){
						auto it = mm.end();
						it--;
						mm.erase(it);
					}
				}
			}
		}
		if (mm.empty()) cout << "EMPTY\n";
		else {
			auto it = mm.end();
			it--;
			cout << *it << " " << *mm.begin() << "\n";
		}
		mm.clear();
	}

	return 0;
}