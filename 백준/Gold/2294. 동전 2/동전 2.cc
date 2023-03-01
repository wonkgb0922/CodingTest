#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int n, k;
int ary[101] = { 0, };
int mem[101][10001];

int solve(int v, int value)
{
    if (v == n) return (value == 0 ? 0 : 1000000);
    if (mem[v][value] != -1) return mem[v][value];

    int res = solve(v + 1, value);
    if (value >= ary[v]) res = min(res, solve(v, value - ary[v]) + 1); // 한번의 동전을 사용했으니 +1
    mem[v][value] = res;

    return res;
}
int main(void){

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ary[i]);

    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            mem[i][j] = -1;
        }
    }
    int r = solve(0, k);
    if (r == 1000000) printf("-1");
    else printf("%d", r);
    return 0;
}