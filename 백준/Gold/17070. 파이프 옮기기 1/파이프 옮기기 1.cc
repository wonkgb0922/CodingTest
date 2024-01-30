#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, ary[16][16], dp[16][16][3];

int sol(int y, int x, int flag) // flag : 0세로, 1가로, 2대각선
{
    if (y == 0 && x == 1 && flag != 0) return 1;
    else if (x <= 1) return 0;
    if (dp[y][x][flag] != -1) return dp[y][x][flag];
    dp[y][x][flag] = 0;
    if (flag == 0) {
        if (y > 0) {
            if (!ary[y - 1][x])
                dp[y][x][flag] += sol(y - 1, x, 0);
            if (!ary[y - 1][x - 1] && !ary[y][x - 1] && !ary[y - 1][x])
                dp[y][x][flag] += sol(y - 1, x - 1, 2);
        }
    }
    else if (flag == 1) {
        if (!ary[y][x - 1])
            dp[y][x][flag] += sol(y, x - 1, 1);
        if (y > 0) {
            if(!ary[y - 1][x - 1] && !ary[y][x - 1] && !ary[y - 1][x])
                dp[y][x][flag] += sol(y - 1, x - 1, 2);
        }
    }
    else {
        if (!ary[y][x - 1])
            dp[y][x][flag] += sol(y, x - 1, 1);
        if (y > 0) {
            if (!ary[y - 1][x])
                dp[y][x][flag] += sol(y - 1, x, 0);
            if (!ary[y - 1][x - 1] && !ary[y][x - 1] && !ary[y - 1][x])
                dp[y][x][flag] += sol(y - 1, x - 1, 2);
        }
    }
    return dp[y][x][flag];
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &ary[i][j]);
    
    int res = 0;
    if (!ary[n - 1][n - 1]) {
        if (!ary[n - 2][n - 1])
            res += sol(n - 2, n - 1, 0);
        if (!ary[n - 1][n - 2])
            res += sol(n - 1, n - 2, 1);
        if (!ary[n - 2][n - 2] && !ary[n - 1][n - 2] && !ary[n - 2][n - 1])
            res += sol(n - 2, n - 2, 2);
    }
    cout << res;

    return 0;
}