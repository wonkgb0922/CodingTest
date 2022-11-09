#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

long long a, b, c;

long long mul(long long cnt)
{
    //printf("%d\n", cnt);
    if (cnt <= 1) return a % c;
    long long temp = mul(cnt / 2) % c;
    if (cnt % 2 == 0)
    {
        return (temp * temp) % c;
    }
    else return (temp * temp) % c * a % c;
}

int main(void) {

    cin >> a >> b >> c;
    cout << mul(b);

    return 0;
}