#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#pragma warning (disable:4996)

using namespace std;


int ary[1001][1001] = { 0 };

int main(void) {
    int n, k;
    cin >> n >> k;

    if (n - k < k) k = n - k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0) ary[i][j] = 1;
            else if (j == 1 || j == i-1) ary[i][j] = i;
            else
            {
                ary[i][j] = (ary[i - 1][j - 1] + ary[i - 1][j]) % 10007;
            }
        }
    }
    printf("%d", ary[n][k]);
    return 0;
}