#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int n, input;
    int ex[3] = { 0 };
    int res[7] = { 0 };
    int sum, cnt;
    vector<int>v;

    for (int i = 0; i < 9; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            sum = 0;
            cnt = 0;
            for (int x = 0; x < 9; x++)
            {
                if (x == i || x == j) continue;
                res[cnt] = v[x];
                cnt++;
               sum += v[x];
            }
            if (sum == 100)
            {
                sort(res, res + 7);
                for (int x = 0; x < 7; x++)
                {
                    printf("%d\n", res[x]);
                }
                return 0;
            }
            
        }
    }



    return 0;
}