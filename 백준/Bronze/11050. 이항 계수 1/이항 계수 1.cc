#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int gcd(int a, int b)
{
    if (a % b) return gcd(b, a % b);
    return b;
}
int fac(int k)
{
    if (k <= 1) return 1;
    else if (k == 2) return 2;
    return fac(k - 1) * k;
}

int main(void) {
    int n, k;
    int p = 1;
    int f;
    cin >> n >> k;

    f = fac(k);
    for (int i = 0; i < k; i++)
    {
        p *= n;
        n--;
    }
    printf("%d", p / f);

    return 0;
}