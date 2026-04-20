#include <iostream>
#include <algorithm>

const long long MAX = 1000000000000000LL;

using namespace std;

struct Node {
	// [l, r)
	long long l, r;
    int sum;
	Node* left;
	Node* right;
	Node(long long l, long long r) :l(l), r(r), sum(0), left(NULL), right(NULL) {
	}

	void extend() {
		if (!left && l + 1 < r) {
			long long mid = (l + r) / 2;
			left = new Node(l, mid);
			right = new Node(mid, r);
		}
	}

	void add(long long k, int value) {
		sum += value;
		if (l + 1 == r) return;
		long long mid = l + (r - l) / 2;
		if (k < mid) {
			if (!left) left = new Node(l, mid);
			left->add(k, value);
		}
		else {
			if (!right) right = new Node(mid, r);
			right->add(k, value);
		}
	}

	int getSum(long long lq, long long rq) {
		if (lq <= l && r <= rq)
			return sum;
		if ((max(l, lq)) >= (min(r, rq))) {
			return 0;
		}
		int res = 0;
		if (left) res += left->getSum(lq, rq);
		if (right) res += right->getSum(lq, rq);
		
		return res;
	}

	long long getkthElement(int k) {
		if (l + 1 == r) return l;
		int leftSum = (left ? left->sum : 0);
		if (leftSum >= k) return left->getkthElement(k);

		return right->getkthElement(k - leftSum);
	}
};

long long ary[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	long long a, b, c;

	cin >> n >> m;
	Node* node = new Node(0, MAX + 1);
	for (int i = 0; i < n; i++) {
		cin >> ary[i];
		node->add(ary[i], 1);
	}

	while (m--) {
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			b--;
			node->add(ary[b], -1);
			ary[b] += c;
			node->add(ary[b], 1);
		}
		else if (a == 2) {
			cin >> c;
			b--;
			node->add(ary[b], -1);
			ary[b] -= c;
			node->add(ary[b], 1);
		}
		else if(a == 3) {
			cin >> c;
			cout << node->getSum(b, c + 1) << "\n";
		}
		else {
			b = n - b + 1;
			cout << node->getkthElement(b) << "\n";
		}
	}
}