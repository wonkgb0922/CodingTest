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

long long cnt = 0;
int ary[21] = { 0 }; // 박스의 갯수


void box(int l, int w, int h)
{
    if (l <= 0 || w <= 0 || h <= 0) return;
    int k = min({ l,w,h });

    //for (int i = 0; i < 3; i++)
    //    printf("%d ", arr[i]);
    //printf("\n");
    
    int index = log2(k);
    int len = 1;
    int it = index;
    while(it>=0)
    {
        if (ary[it] > 0) break;
        it--;
    }
    if (it < 0)
    {
        cnt = -1;
        printf("-1");
        exit(0);
    }
    
    // 최대한 가장 큰 박스를 채울 수 있으면 채워넣기 그리고 재귀호출
    ary[it]--;
    cnt++;
    len = pow(2, it);
    box(l - len, w, h);
    box(len, w, h- len);
    box(len, w- len, len);
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
    box(l, w, h);
    printf("%lld", cnt);
    return 0;
}