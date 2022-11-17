#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int ary[2188][2188] = { 0 };
int mone = 0, zero = 0, one = 0; // -1, 0, 1;
void sol(int bi, int bj, int ei, int ej)
{
    int temp = ary[bi][bj];
    bool no = false;
    for (int i = bi; i < ei; i++)
    {
        for (int j = bj; j < ej; j++)
        {
            if (temp != ary[i][j])
            {
                no = true;
                break;
            }
        }
        if (no) break;
    }
    if (!no)
    {
        if (temp == 0) zero++;
        else if (temp == -1) mone++;
        else one++;
    }
    else
    {
        temp = (ei - bi) / 3;
        //int tempj = (ej - bj) / 3;
        //int tempi = (ei - bi) / 3;
        for (int i = bi; i < ei; i += temp)
        {
            for (int j = bj; j < ej; j += temp)
                sol(i, j, i + temp, j + temp);
        }
    }
}

int main(void) {
    int n, input;
    int res;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> ary[i][j];
    }

    sol(0, 0, n, n);
    printf("%d\n%d\n%d\n", mone, zero, one);
    return 0;
}