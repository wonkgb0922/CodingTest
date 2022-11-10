#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

long long ary[100001] = { 0 };

long long arr(int b, int e)
{
    //printf("b : %d, e : %d\n", b, e);
    if (b == e) return ary[b];
    int mid = (b + e) / 2;
    long long MAX = max(arr(b, mid), arr(mid+1, e));
    
    int i = mid;
    int j = mid;
    long long res;
    long long MIN = ary[mid];

    long long len = 1;

    //printf("\nb : %d, e : %d\n", b, e);
    while (true)
    {
        res = len * MIN;
        //printf("%d %d : %lld %lld,,, %lld\n", i, j, sum, MIN, res);
        MAX = max(MAX, res);

        if (i > b)
        {
            if (j < e)
            {
                // 유효한 경우
                if (ary[i - 1] > ary[j + 1])
                {
                    // 왼편이 더 크면
                    i--;
                    len++;
                    MIN = min(MIN, ary[i]);
                }
                else
                {
                    // 오른쪽이 더 크면
                    j++;
                    len++;
                    MIN = min(MIN, ary[j]);

                }
            }
            else
            {
                // j만 끝에 다다름, i만 유효
                i--;
                len++;
                MIN = min(MIN, ary[i]);
                
            }
        }
        else
        {
            // i는 끝에 다다름
            if (j < e)
            {
                // j만 유효할 때
                j++;
                len++;
                MIN = min(MIN, ary[j]);
            }
            else
            {
                break;
            }
        }
    }
    return MAX;    
}
int main(void) {
    int n, input;
    int res;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> ary[i];
    }
    
    cout << arr(0, n-1);

    return 0;
}