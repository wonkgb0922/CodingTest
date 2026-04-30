#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#define MAX 300001

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	string s;
	int n, cnt;
	bool flag;
	map<int, int> m;
	for (int tc = 1; tc <= T; tc++) {
		cin >> s;
		m = map<int, int>();
		for (auto& it : s) {
			n = it - '1';
			if (m.find(n) == m.end())
				m.insert({ n, 0 });
			m[n]++;
			if (m[n] == 3) m.erase(n);
		}
		n = -1;
		cnt = 0;
		flag = m.empty();
		for (auto& it : m) {
			if (n + 1 == it.first)
				cnt++;
			else cnt = 0;
			if (cnt == 2) flag = true;
			if (flag) break;
			n = it.first;
		}
		
		cout << '#' << tc << " " << (flag ? "true\n" : "false\n");
	}
	
	return 0;
}