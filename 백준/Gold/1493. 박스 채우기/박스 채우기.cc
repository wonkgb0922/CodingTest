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

int maax = 0;
long long cnt = 0;
int ary[21] = { 0 }; // 박스의 갯수


void box(int l, int w, int h, int c_index)
{
    if (l <= 0 || w <= 0 || h <= 0) return;
    int k = min({ l,w,h });

    //for (int i = 0; i < 3; i++)
    //    printf("%d ", arr[i]);
    //printf("\n");
    
    int index = c_index;
    int len = 1;
    for (int i = 0; i < index; i++)
    {
        len *= 2;
    }
    while (index >= 0)
    {
        if (len <= k && ary[index] > 0)
        {
            // 최대한 가장 큰 박스를 채울 수 있으면 채워넣기 그리고 재귀호출
            ary[index]--;
            cnt++;
            box(l - len, w, h, index);
            box(len, w, h- len, index);
            box(len, w- len, len, index);
            break;
        }
        index--;
        len /= 2;
    }
    if (index < 0)
    {
        printf("-1");
        exit(0);
    }
}

int main(void) {
    int n;
    int a, b;
    int l, w, h; // 전체 박스의 길이

    cin >> l >> w >> h;
    cin >> n; 
    
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        ary[a] = b;
        //if (maax < a) maax = a;
    }
    maax = n - 1;
    box(l, w, h, maax);
    printf("%lld", cnt);
    return 0;
}