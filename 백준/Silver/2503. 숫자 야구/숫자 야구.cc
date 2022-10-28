#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int n;
    const int _MAX = 877;
    int num, s, b;
    int ts, tb;

    int ary[_MAX];
    int r[3], t[3],tmp;
    int fix1, fix2, cnt = 0;;


    cin >> n;

    for (int i = 0; i < _MAX; i++)
    {
        ary[i] = i + 123;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> num >> s >> b;
        
        for (int j = 2; j >= 0; j--)
        {
            r[j] = num % 10;
            num /= 10;
        }
        for (int j = 0; j < _MAX; j++)
        {
            ts = 0;
            tb = 0;
            if (ary[j] == 0) continue;

            tmp = ary[j];
            for (int k = 2; k >= 0; k--)
            {
                t[k] = tmp % 10;
                tmp /= 10;
            }
            if (t[0] == t[1] || t[0] == t[2] || t[1] == t[2] || t[0] == 0 || t[1] == 0 || t[2] == 0)
            {
                ary[j] = 0;
                continue;
            }

            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if (r[k] == t[l])
                    {
                        if (k == l) ts++;
                        else tb++;
                    }
                }
            }
            if (ts == s && tb == b);
            else ary[j] = 0;
        }
    }
    for (int i = 0; i < _MAX; i++)
    {
        if (ary[i] != 0)
        {
            //printf("%d\n", ary[i]);
            cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}