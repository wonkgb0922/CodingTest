#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int hashing(string in) {
	unsigned long long int hash = 0;
	for (int i = 0; i < in.length(); i++) {
		hash += (in[i] - 96) * pow(27, (in.length() - i - 1));
	}
	//cout << in;
	//printf("의 해시값 : %d\n", hash % 7919);
	return hash % 7919;
}
int main()
{
	int n, cnt = 0;
	int hash;
	bool sol;
	string in, temp;
	multimap<int, string> v;
	cin >> n;
	while (n--) {
		sol = true;
		cin >> in;
		for (int i = 0; i < in.length(); i++) {
			hash = hashing(in);
			auto it = v.equal_range(hash);
			if (it.first != v.end()) {
				//cout << "in : " << in << endl;
				//cout << "it-> : " << it->second << endl;
				for (auto r = it.first; r != it.second; r++) {
					if (r->second == in) {
						sol = false;
						break;
					}
				}
			}
			temp = in[0];
			in.erase(0, 1);
			in += temp;
		}
		if (sol) {
			hash = hashing(in);
			v.insert({ hash, in });
		}		
	}	
	cout << v.size();

	return 0;
}