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
    int n;
    int cnt1 = 0, cnt2 = 0; // 2의 약수의 갯수, 5의 약수의 갯수
    int temp, cnt;

    cin >> n;
    if (n <= 4)
    {
        printf("0");
        return 0;
    }
    for (int i = n; i >= 2; i--)
    {
        temp = i;
        while (temp % 2 == 0)
        {
            cnt1++;
            temp /= 2;
        }
        while (temp % 5 == 0)
        {
            cnt2++;
            temp /= 5;
        }
    }
    cnt = min(cnt1, cnt2);
    printf("%d", cnt);

    return 0;
}