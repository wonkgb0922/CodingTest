#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int ary[1000001] = { 0 };

int solve(int n)
{
    if (n == 1) return 0;
    if (ary[n] != -1) return ary[n];

    int res = solve(n - 1) + 1;
    
    if (n % 3 == 0) res = min(res, solve(n / 3) + 1);
    if (n % 2 == 0) res = min(res, solve(n / 2) + 1);
    ary[n] = res;
    return res;
}

int main(void){
    int n;
    scanf("%d", &n);
    fill(ary, ary + 1000001, -1);
    cout << solve(n);
    return 0;
}