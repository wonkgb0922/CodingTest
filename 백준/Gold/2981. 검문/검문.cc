#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int gcd(int a, int b) // 최대 공약수
{
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main(void) {
    int n, cnt = 0;
    int a, min;
    int v[101] = { 0, };
    int m[500] = { 0, };

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v, v + n);

    min = v[1] - v[0];
    for (int i = 2; i < n; i++)
    {        
        min = gcd(min, v[i] - v[i - 1]);
    }

    for (int i = 2; i * i <= min; i++)
    {
        if (min % i == 0)
        {
            m[cnt++] = i;
            if(i*i != min)
                m[cnt++] = min / i;
        }
    }
    m[cnt++] = min;
    sort(m, m + cnt);
    for (int i = 0; i < cnt; i++) printf("%d ", m[i]);
    
    /*
    // 시간 초과 소스, long long 쓸 필요도 없었음
    long long temp;
    int j;
    for (long long i = 2; i <= v[v.size()-1]; i++)
    {
        temp = v[0] % i;
        for (j = 1; j < v.size(); j++)
        {
            if (v[j] % i != temp) break;
        }
        if (j == v.size()) printf("%lld ", i);
    }*/
    return 0;
}