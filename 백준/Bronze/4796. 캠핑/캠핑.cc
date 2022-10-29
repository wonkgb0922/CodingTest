#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int n;
    int p, l, v, cnt;

    for (int i = 1;; i++)
    {
        cin >> l >> p >> v;
        cnt = 0;
        if (l == 0 && p == 0 && v == 0) break;
        while (p <= v)
        {
            v -= p;
            cnt += l;
        }
        if (l > v) cnt += v;
        else cnt += l;
        printf("Case %d: %d\n", i, cnt);
    }

    return 0;
}