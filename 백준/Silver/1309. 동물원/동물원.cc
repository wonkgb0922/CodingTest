#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, dp[100000][3];

int sol(int idx, int loc)
{
    if (idx == 0) return 1;
    if (dp[idx][loc]) return dp[idx][loc];
    if (loc == 0) {
        dp[idx][loc] = sol(idx - 1, 0) + sol(idx - 1 , 1) + sol(idx - 1, 2);
    }
    else if (loc == 1) {
        dp[idx][loc] = sol(idx - 1, 0) + sol(idx - 1, 2);
    }
    else {
        dp[idx][loc] = sol(idx - 1, 0) + sol(idx - 1, 1);
    }
    dp[idx][loc] %= 9901;
    return dp[idx][loc];
}

int main() {
    cin >> n;
    cout << (sol(n - 1, 0) + sol(n - 1, 1) + sol(n - 1, 2)) % 9901;
    return 0;
}