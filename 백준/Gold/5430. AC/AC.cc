#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int t, n, len;
	bool isError, rvs;
	string p, in, sum;
	deque<int> dq;

	scanf("%d", &t);
	while (t--) {
		isError = false;
		rvs = false;
		sum = "";
		cin >> p;
		scanf("%d", &n);
		cin >> in;

		in.erase(0,1);
		in.erase(in.length() - 1, 1);
		len = in.length();
		for (int i = 0; i < len; i++) {
			if (in[i] == ',') {
				dq.push_back(stoi(sum));
				sum = "";
				n--;
			}
			else sum += in[i];
		}
		if (n >= 1) {
			dq.push_back(stoi(sum));
		}
		//for (auto& x : dq) {
		//	cout << x << " ";
		//}
		//cout << endl;
		len = p.length();
		for (int i = 0; i < len; i++) {
			if (p[i] == 'R') {
				rvs = !rvs;
			}
			else if (p[i] == 'D') {
				if (!dq.empty()) {
					if (rvs) dq.pop_back();
					else dq.pop_front();
				}
				else {
					printf("error\n");
					isError = true;
					break;
				}
			}
		}
		if (!isError) printf("[");
		if (rvs) {
			for(auto it = dq.rbegin(); it != dq.rend(); it++) {
				printf("%d", *it);
				if (it != dq.rend() - 1) printf(",");
			}
		}
		else {
			for (auto it = dq.begin(); it != dq.end(); it++) {
				printf("%d", *it);
				if (it != dq.end() - 1) printf(",");
			}
		}
		if (!isError) printf("]\n");
		//dq.clear();
		dq = deque<int>();
	}
	return 0;
}