#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int ary[2][100001] = { 0, };
int mem[3][100001] = { 0, };
int n;

int solve(int c, int status)
{
    if (c == n) return 0;
    if (mem[status][c] != -1) return mem[status][c];

    int res = solve(c + 1, 0);
    if (status != 1) res = max(res, solve(c + 1, 1) + ary[0][c]);
    if (status != 2) res = max(res, solve(c + 1, 2) + ary[1][c]);

    mem[status][c] = res;

    return res;
    
}
int main(void){
    int t;

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> ary[i][j];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mem[i][j] = -1;
            }
        }

        cout << solve(0, 0) << "\n";
    }
    return 0;
}