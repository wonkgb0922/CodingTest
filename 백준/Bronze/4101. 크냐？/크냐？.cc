#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int in1, in2;
    for (;;) {
        scanf("%d%d", &in1, &in2);
        if (in1 == 0 && in2 == 0) break;
        if (in1 > in2) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}