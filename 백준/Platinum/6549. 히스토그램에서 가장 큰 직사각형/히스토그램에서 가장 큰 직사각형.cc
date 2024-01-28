#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ary[100001];

long long arr(int b, int e)
{
    if (b == e) return ary[b];
    int mid = (b + e) / 2;

    int i = mid,  j = mid;
    long long res, MAX = max(arr(b, mid), arr(mid + 1, e)), MIN = ary[mid];
    long long len = 1;

    while (true) {
        res = len * MIN;
        MAX = max(MAX, res);

        if (i > b) {
            if (j < e) {
                if (ary[i - 1] > ary[j + 1]) {
                    i--;
                    len++;
                    MIN = min(MIN, ary[i]);
                }
                else {
                    j++;
                    len++;
                    MIN = min(MIN, ary[j]);
                }
            }
            else {
                i--;
                len++;
                MIN = min(MIN, ary[i]);
            }
        }
        else {
            if (j < e) {
                j++;
                len++;
                MIN = min(MIN, ary[j]);
            }
            else break;
        }
    }
    return MAX;
}
int main(void) {
    int n;

    while (true) {
        scanf("%d", &n);
        if (!n) break;
        for (int i = 0; i < n; i++)
            scanf("%d", ary + i);
        printf("%lld\n", arr(0, n - 1));
    }

    return 0;
}