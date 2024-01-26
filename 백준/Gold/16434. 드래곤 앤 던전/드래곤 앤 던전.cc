#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int l = 1, r = 9223372036854775807, mid, hp, atk, satk, m_hp, ans;
long long int ary[123457][3];

int main()
{
	int N;

	cin >> N >> atk;
	for (int i = 0; i < N; i++)
		scanf("%lld%lld%lld", &ary[i][0], &ary[i][1], &ary[i][2]);
	while (r >= l) {
		mid = (l + r) / 2;
		hp = mid;
		satk = atk;
		for (int i = 0; i < N; i++) {
			if (ary[i][0] == 1) {
				m_hp = ary[i][2] - satk;
				if (m_hp > 0) {
					hp -= (m_hp / satk) * ary[i][1];
					if (m_hp % satk > 0) hp -= ary[i][1];
				}
				if (hp <= 0) break;
			}
			else {
				satk += ary[i][1];
				hp += ary[i][2];
				if (hp > mid) hp = mid;
			}
		}
		if (hp <= 0) l = mid + 1;
		else {
			r = mid - 1;
			ans = mid;
		}
	}
	printf("%lld", ans);
	
	return 0;
}