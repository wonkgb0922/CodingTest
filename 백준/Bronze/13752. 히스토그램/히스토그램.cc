#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n, in;
    cin >> n;
    while (n--) {
        scanf("%d", &in);
        while (in--) printf("=");
        printf("\n");
    }
    return 0;
}