#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int t;
    long long x1, y1, r1;
    long long x2, y2, r2;

    int res;

    cin >> t;
    while (t--)
    {
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;

        if (x1 == x2 && y1 == y2)
        {
            if (r1 == r2) res = -1;
            else res = 0;
        }
        else
        {
            long long R1, R2, dis1;
            R1 = (r1 + r2) * (r1 + r2);
            R2 = (r1 - r2) * (r1 - r2);
            
            dis1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
            if (R1 == dis1 || R2 == dis1) res = 1;
            else if (R1 < dis1 || R2 > dis1) res = 0;
            else res = 2;
        }
        printf("%d\n", res);
       
    }

    return 0;
}