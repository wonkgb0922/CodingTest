#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int t, n, in, root;
	priority_queue<int> q1;
	priority_queue<int, vector<int>, greater<>> q2;
	vector<int> res;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		if (i == 0)
			root = in;
		else {
			if (q1.size() < q2.size()) {
				if (q2.top() < in) {
					q1.push(root);
					root = q2.top();
					q2.pop();
					q2.push(in);
				}
				else if (root < in) {
					q1.push(root);
					root = in;
				}
				else q1.push(in);
			}
			else {
				if (!q1.empty()) {
					if (q1.top() > in) {
						q2.push(root);
						root = q1.top();
						q1.pop();
						q1.push(in);
					}
					else if (root >= in) {
						q2.push(root);
						root = in;
					}
					else q2.push(in);
				}
				else {
					if (root < in) q2.push(in);
					else {
						q2.push(root);
						root = in;
					}
				}
			}
		}
		printf("%d\n", root);
	}
	return 0;
}