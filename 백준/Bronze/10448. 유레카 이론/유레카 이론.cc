#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int n, input;
    int t1, t2, t3;
    int temp1, temp2, temp3;
    bool solve;
    int t;

    cin >> t;

    while (t--)
    {
        cin >> input;
        t1 = 0;
        t2 = 0;
        t3 = 0;
        solve = false;
        for (int i = 1; i < input; i++)
        {
            t1 = i * (i + 1) / 2;
            if (t1 * 3 == input) // 삼각수의 3배일때
            {
                solve = true;
                break;
            }

            temp1 = input - t1; // t1고정
            for (int j = 1; j < temp1; j++)
            {
                t2 = j * (j + 1) / 2;
                if (t2 * 2 == temp1) // 삼각수의 1+2인 경우
                {
                    solve = true;
                    break;
                }

                temp2 = temp1 - t2;
                for (int k = 1; k < temp2; k++)
                {
                    t3 = k * (k + 1) / 2;
                    if (t3 == temp2) // 삼각수의 1+2인 경우
                    {
                        solve = true;
                        break;
                    }
                }
                if (solve) break;
            }
            if (solve) break;
        }
        if (solve) printf("1\n");
        else printf("0\n");
    }




    return 0;
}