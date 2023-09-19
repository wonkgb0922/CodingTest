#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) printf(" ");
        for (int j = 0; j < 2 * (n - i) - 1; j++) printf("*");
        printf("\n");
    }
    return 0;
}