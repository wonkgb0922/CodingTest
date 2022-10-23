#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int a, b, t;
    int i;
    int min=1, max=1;

    cin >> t;
    while (t--)
    {
        max = 1;
        min = 1;
        cin >> a >> b;
        if (a > b) swap(a, b);
        for (i = 2; i <= a; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                min *= i;
                a /= i;
                b /= i;
                i = 1;
                continue;
            }
        }
        max = min * a * b;

        printf("%d\n", max);
    }

    

    return 0;
}