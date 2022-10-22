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
    int x, y;

    while (true)
    {
        cin >> x >> y;

        if (x == 0 && y == 0) break;
        if (x > y) // 배수일 가능성 검토
        {
            int i = 2;
            while (y * i < x)
            {
                if (y * i == x) break;
                i++;
            }
            if (y * i == x) printf("multiple\n");
            else printf("neither\n");
        }
        else
        {
            int i = 2;
            while (x * i < y)
            {
                if (x * i == y) break;
                i++;
            }
            if (x * i == y) printf("factor\n");
            else printf("neither\n");
        }
    }

    return 0;
}