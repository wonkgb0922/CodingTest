#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int l = 1, r, mid, temp;
	int N, K;
	long long int D, cnt = 0;
	int ary[10000][3];

	cin >> N >> K >> D;
	for (int i = 0; i < K; i++)
		scanf("%d%d%d", &ary[i][0], &ary[i][1], &ary[i][2]);
	r = N;
	while (r >= l) {
		mid = (l + r) / 2;
		cnt = 0;
		for (int i = 0; i < K; i++) {
			temp = min(ary[i][1], mid);
			if (ary[i][0] == temp)
				cnt++;
			else if (ary[i][0] > temp);
			else cnt += (temp - ary[i][0]) / ary[i][2] + 1;
		}
		if (cnt >= D) r = mid - 1;
		else l = mid + 1;
	}
	cout << l;
	return 0;
}