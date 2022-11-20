#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int ary[65][65] = { 0 };

void sol(int bi, int bj, int cnt)
{
    if (cnt == 1)
    {
        printf("%d", ary[bi][bj]);
        return;
    }
    bool ONE = true, ZERO = true;
    for (int i = bi; i < bi + cnt; i++)
    {
        for (int j = bj; j < bj + cnt; j++)
        {
            if (ary[i][j] == 0) ONE = false;
            else ZERO = false;
        }
        if (!ONE && !ZERO) break;
    }
    if (ONE || ZERO)
    {
        if (ONE) printf("1");
        else printf("0");
        return;
    }
    else
    {
        printf("(");
        sol(bi, bj, cnt / 2);
        sol(bi, bj + cnt / 2, cnt / 2);
        sol(bi + cnt / 2, bj, cnt / 2);
        sol(bi + cnt / 2, bj + cnt / 2, cnt / 2);
        printf(")");
    }
}

int main(void) {
    int n;
    string input;
    int res;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        for (int j = 0; j < n ; j++)
        {
            ary[i][j] = input[j]- '0';
        }
    }
    
    sol(0, 0, n);
    return 0;
}