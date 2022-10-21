#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define PI 3.141592653589793

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int n;
    long long x1, y1, r1, x2, y2, r2;
    int res;

    cin >> n;

    while (n--)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if (x1 == x2 && y1 == y2)
        {
            if (r1 == r2) res = -1;
            else res = 0;
        }
        else
        {
            long long dx = (x1 - x2) * (x1 - x2);
            long long dy = (y2 - y1) * (y2 - y1);

            long long dis = dx + dy;

            long long ar = (r1 + r2) * (r1 + r2);
            long long sr = (r1 - r2) * (r1 - r2);

            //if (dis < 0) dis *= -1;
            if (dis == ar || dis == sr) res = 1;
            else if (dis < ar && dis > sr) res = 2;
            else if (dis < sr || dis > ar) res = 0;
        }

        printf("%d\n", res);
    }


    return 0;
}