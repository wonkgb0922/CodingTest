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

long long func(int n, int k)
{
    long long num = 0;
    for (long long i = k; i <= n; i *= k)
    {
        num += n / i;
    }
    return num;
}

int main(void) {
    int t;
    int n, m;
    int cnt = 0;
    long long two = 0, five = 0;
    int temp, temp2;

    cin >> n >> m;

    two = func(n, 2) - func(n - m, 2) - func(m, 2);
    five = func(n, 5) - func(n - m, 5) - func(m, 5);

    // 시간초과 코드
    /*for(int i = 0; i < m; i++)
    {
        temp = n - i;
        temp2 = i + 1;

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
        while (temp2 % 2 == 0)
        {
            temp2 /= 2;
            two--;
        }
        while (temp2 % 5 == 0)
        {
            temp2 /= 5;
            five--;
        }
    }
    */
    //cnt = (two > five) ? five : two;
    cout << min(two, five);
    return 0;
}