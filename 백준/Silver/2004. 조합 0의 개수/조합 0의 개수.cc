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

long long count(long long n, long long k)
{
    long long cnt = 0;
    long long temp;
    for (long long i = 1; i <= n; i *= k)
    {
        cnt += n / i;
    }
    return cnt;
}

int main(void) {
    long long n, k;
    long long two, five, cnt;
    cin >> n >> k;

    two = count(n, 2) - count(k, 2) - count(n - k, 2);
    five = count(n, 5) - count(k, 5) - count(n - k, 5);

    cout << min(two, five);
    return 0;
}