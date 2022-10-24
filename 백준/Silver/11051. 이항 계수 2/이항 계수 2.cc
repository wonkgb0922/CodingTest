#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;
long long gcd(long long a, long long b)
{
    if (a % b) return gcd(b, a % b);
    return b;
}
// DP TOP-DOWN 실패
//long long res(long long n, long long k)
//{
//    if (ary[n][k] != 0) return ary[n][k];
//    if (n == k)
//    {
//        ary[n][k] = 1;
//    }
//    else
//    {
//        if (k > n - k) k -= n;
//        if (k <= 1)
//        {
//            ary[n][k] = n;
//        }
//        else ary[n][k] = res(n - 1, k - 1) + res(n - 1, k);
//    }
//    return ary[n][k];
//}

int  ary[1001][1001] = {0};

int main(void) {
    int n, k;

    cin >> n >> k;
   //if (k > n - k) k -= n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == j || j == 0) ary[i][j] = 1;
            else if(j == 1) ary[i][j] = i;
            else ary[i][j] = (ary[i - 1][j - 1] + ary[i - 1][j]) % 10007;
        }
    }
    printf("%d", ary[n][k]);

    return 0;
}