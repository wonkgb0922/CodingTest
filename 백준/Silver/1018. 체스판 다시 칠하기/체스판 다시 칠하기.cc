#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void){
    int n, m, cnt, cnt1, cnt2;
    char ary[50][50];
    char WB[8][8] = {
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'} };
    char BW[8][8] = {
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'}};
    char input;
    int k = 0, l = 0, min = -1;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> input;
            ary[i][j] = input;
        }
    }
    while(k <= n - 8)
    {
        while(l <= m - 8)
        {
            cnt = 0;
            cnt1 = 0;
            cnt2 = 0;
            for (int i = k; i < k + 8; i++)
            {
                for (int j = l; j < l + 8; j++)
                {
                    if (ary[i][j] != WB[i-k][j-l]) cnt1++;
                    if (ary[i][j] != BW[i-k][j-l]) cnt2++;
                }
                
            }
            cnt = (cnt1 > cnt2) ? cnt2 : cnt1;
            if (cnt < min || min == -1) min = cnt;
            l++;
        }        
        l = 0;
        k++;
    }
    printf("%d", min);
	return 0;
    
}