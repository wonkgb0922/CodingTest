#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct Comp {
public:
	bool operator () (const string& a, const string& b) const {
		if (a.length() == b.length()) return a < b;
		else return a.length() < b.length();
	}
};

set<string, Comp> s;

int main(void) {
	int n;
	bool d;
	string in;

	cin >> n;
	for (int i = 0; i < n; i++) {
		d = false;
		cin >> in;
		s.insert(in);
	}

	for (auto& it : s)
		cout << it << "\n";
	return 0;

}