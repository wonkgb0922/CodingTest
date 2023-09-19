#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int ary[5];
int main()
{
    int in, res1, res2 = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &in);
            ary[i] += in;
        }
        if (res2 < ary[i]) {
            res2 = ary[i];
            res1 = i + 1;
        }
    }
    printf("%d %d", res1, res2);
    return 0;
}