#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define PI 3.141592653589793

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int t, n;
    int x1, x2, y1, y2;
    int X[50], Y[50], R[50];
    int res = 0;;

    cin >> t;

    while (t--)
    {
        res = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> X[i] >> Y[i] >> R[i];
            int dis1 = ((X[i] - x1) * (X[i] - x1)) + ((Y[i] - y1) * (Y[i] - y1)); // x1,y1에서 원 중점까지 거리의 제곱
            int dis2 = ((X[i] - x2) * (X[i] - x2)) + ((Y[i] - y2) * (Y[i] - y2)); // x2,y2에서 원 중점까지 거리의 제곱

            if (dis1 < R[i] * R[i] && dis2 < R[i] * R[i]); // 두 중점이 모두 원 안에 있는 경우
            else if (dis1 < R[i] * R[i]) res++;
            else if (dis2 < R[i] * R[i]) res++;
        }
        printf("%d\n", res);
    
    }


    return 0;
}