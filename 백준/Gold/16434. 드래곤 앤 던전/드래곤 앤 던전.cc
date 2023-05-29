#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

long long int l = 1, r = 9223372036854775807, mid, hp, atk, satk, ans;
long long int ary[123457][3];

int main(void)
{
	int N;

	cin >> N >> atk;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld%lld%lld", &ary[i][0], &ary[i][1], &ary[i][2]);
		//if (ary[i][0] == 1) r += ary[i][1] * ary[i][2];
		//if (r > 9223372036854775807) r = 9223372036854775807;
	}
	while (r >= l)
	{
		mid = (l + r) / 2;
		hp = mid;
		satk = atk;
		//printf("%lld %lld %lld\n", l, mid, r);
		for (int i = 0; i < N; i++)
		{
			if (ary[i][0] == 1)
			{
				// 몬스터와 조우시
				if (ary[i][2] % satk == 0) hp -= ((ary[i][2] / satk) - 1) * ary[i][1];
				else hp -= (ary[i][2] / satk) * ary[i][1];
				//printf("hp : %lld\n", hp);
				if (hp <= 0)
				{
					// 사망시
					break;
				}
			}
			else
			{
				satk += ary[i][1];
				hp = min(ary[i][2] + hp, mid);
			}
		}
		
		if (hp <= 0) l = mid + 1;
		else {
			r = mid - 1;
			ans = mid;
		}
	}
	printf("%lld", ans);
	
}