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

int  ary[1001][1001] = {0};

int main(void) {
    int t;
    int n, m;
    int cnt = 0;
    int two = 0, five = 0;
    int temp;

    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        temp = i;
        while(temp % 2 == 0)
        {
            temp /= 2;
            two++;
        }
        while (temp % 5 == 0)
        {
            temp /= 5;
            five++;
        }
    }
    cnt = (two > five) ? five : two;
    printf("%d\n", cnt);

    return 0;
}