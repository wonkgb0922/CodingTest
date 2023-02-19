#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int n;
int ary[20][20][2] = { 0 };

int available(int bi, int ei, int bj, int ej, int d)
{
    int cnt[3] = { 0, };
    for (int i = bi; i <= ei; i++)
    {
        for (int j = bj; j <= ej; j++)
        {
            cnt[ary[i][j][d]]++;
        }
    }
    //printf("%d %d %d, d: %d\n", cnt[0], cnt[1], cnt[2], d);

    if (cnt[2] == 0) return 0; // 결정체가 없는 경우는 안됨
    if (cnt[2] == 1)
    {
        if (cnt[1] == 0) return 1; // 결정체가 하나면서 불순물이 없는 경우 ok
        else return 0; // 결정체가 하나있고, 불순물이 있으니 안됨
    }
    if (cnt[1] == 0) return 0; // 결정체가 둘 이상인데 불순물이 없으니 자를 수가 없음

    return 2; // 더 잘라야 됨
}

int solve(int bi, int ei, int bj, int ej, int d) // d가 0이면 가로로, 1이면 뒤집어 세로로 자르기
{
    int k = available(bi, ei, bj, ej, d);
    if (k == 0) return 0;
    else if (k == 1) return 1;
    int x, y;
    int first, second, cnt = 0;
    
    bool find;
    for (y = bi + 1; y < ei; y++)
    {
        find = false;
        for (x = bj; x <= ej; x++)
        {
            //printf("%d ", ary[y][x][d]);
            if (ary[y][x][d] == 2) // 보석이 있는곳은 경계선으로 삼을 수 없음.
            {
                find = false;
                break;
            }
            else if (ary[y][x][d] == 1) find = true; // 불순물을 찾았으나, 같은 행에 보석이 있을지도 모르니 대기.
        }
        //printf("\n");
        if (!find) continue;

        //cout << "find 입장 " << d << " y: " <<  y << endl;
        if (d == 0)
        {
            first = solve(bj, ej, bi, y - 1, 1);
            if (first == 0) continue;

            second = solve(bj, ej, y + 1, ei, 1);
            if (second == 0) continue;
             
            cnt += first * second;
        }
        else
        {
            first = solve(bj, ej, bi, y - 1, 0);
            if (first == 0) continue;
            second = solve(bj, ej, y + 1, ei, 0);
            if (second == 0) continue;
         
            cnt += first * second;
        }
    }
    return cnt;
}


int main(void){
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &ary[i][j][0]);
            ary[j][i][1] = ary[i][j][0];
        }
    }
    int res = solve(0, n - 1, 0, n - 1, 0) + solve(0, n - 1, 0, n - 1, 1);
    if (res == 0) printf("-1");
    else printf("%d", res);

    return 0;
}