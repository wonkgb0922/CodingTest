#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int n, input;
    char ary[50][50] = { 0 };
    char temp1, temp2, temp3; // 행, 첫번째열, 두번째열, 혹은 첫번째 행, 두번째 행, 열
    int max = 0, cnt1, cnt2, cnt3;
    
    vector<int>v;

    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cnt1 = 1;
        cin >> ary[i][0];
        temp1 = ary[i][0];
        for (int j = 1; j < n; j++)
        {
            cin >> ary[i][j];
            if (temp1 == ary[i][j]) cnt1++;
            else
            {
                if (max < cnt1) max = cnt1;
                cnt1 = 1;
                temp1 = ary[i][j];
            }
        }
        if (max < cnt1) max = cnt1;
    }
    if (max == n)
    {
        printf("%d", max);
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cnt1 = 1;
            cnt2 = 1;
            cnt3 = 1;
            
            // 오른쪽 값과 같은지 다른지 검사.
            if (j != n-1) // j가 맨 오른쪽 끝을 가리킬 경우 안함
            {
                if (ary[i][j] != ary[i][j + 1])
                {
                    std::swap(ary[i][j], ary[i][j + 1]);
                    temp1 = ary[i][0];
                    temp2 = ary[0][j];
                    temp3 = ary[0][j + 1];
                    for (int k = 1; k < n; k++)
                    {
                        // 행 검사
                        if (temp1 == ary[i][k]) cnt1++;
                        else
                        {
                            if (max < cnt1) max = cnt1;
                            temp1 = ary[i][k];
                            cnt1 = 1;
                        }
                        // 열1 검사
                        if (temp2 == ary[k][j]) cnt2++;
                        else
                        {
                            if (max < cnt2) max = cnt2;
                            temp2 = ary[k][j];
                            cnt2 = 1;
                        }
                        // 열2 검사
                        if (temp3 == ary[k][j + 1]) cnt3++;
                        else
                        {
                            if (max < cnt3) max = cnt3;
                            temp3 = ary[k][j + 1];
                            cnt3 = 1;
                        }
                    }
                    if (max < cnt1) max = cnt1;
                    if (max < cnt2) max = cnt2;
                    if (max < cnt3) max = cnt3;

                    if (max == n)
                    {
                        printf("%d", max);
                        return 0;
                    }
                    std::swap(ary[i][j], ary[i][j + 1]);
                }
                
            }
            if (i != n - 1) // i가 맨 마지막 열을 가리키지 않으면
            {
                cnt1 = 1;
                cnt2 = 1;
                cnt3 = 1;
                if (ary[i][j] != ary[i + 1][j])
                {
                    std::swap(ary[i][j], ary[i + 1][j]);
                }
                temp1 = ary[i][0];
                temp2 = ary[i+1][0];
                temp3 = ary[0][j];
                for (int k = 1; k < n; k++)
                {
                    // 행1 검사
                    if (temp1 == ary[i][k]) cnt1++;
                    else
                    {
                        if (max < cnt1) max = cnt1;
                        temp1 = ary[i][k];
                        cnt1 = 1;
                    }
                    // 행2 검사
                    if (temp2 == ary[i + 1][k]) cnt2++;
                    else
                    {
                        if (max < cnt2) max = cnt2;
                        temp2 = ary[i + 1][k];
                        cnt2 = 1;
                    }
                    // 열 검사
                    if (temp3 == ary[k][j]) cnt3++;
                    else
                    {
                        if (max < cnt3) max = cnt3;
                        temp3 = ary[k][j];
                        cnt3 = 1;
                    }
                }
                if (max < cnt1) max = cnt1;
                if (max < cnt2) max = cnt2;
                if (max < cnt3) max = cnt3;

                if (max == n)
                {
                    printf("%d", max);
                    return 0;
                }
                
                std::swap(ary[i][j], ary[i + 1][j]);
            }
            
        }
    }
    printf("%d", max);



    return 0;
}