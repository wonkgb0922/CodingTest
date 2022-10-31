#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int n, k;
    int input;
    int cnt = 0;
    int max, l, maxi;

    vector<int> v, res;
    cin >> n >> k;

    for(int i = 0; i < k; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    for (int i = 0; i < k; i++)
    {
        sort(res.begin(), res.end());
        if (!binary_search(res.begin(), res.end(), v[i])) // 같은 전자기기가 꽃혀있지 않은 경우
        {
            if (res.size() < n)
            {
                res.push_back(v[i]); // 콘센트가 비어있으면 꽃는다
            }
            else
            {
                max = -1;
                maxi = -1;
                //for (auto x : res) printf("%d ", x);
                //printf("\n");
                for (int j = 0; j < res.size(); j++)
                {
                    for (l = i+1; l < k; l++)
                    {
                        if (res[j] == v[l]) break;
                    }
                    if (l > max)
                    {
                        max = l;
                        maxi = j;
                    }
                }
                res[maxi] = v[i];
                cnt++;
                //printf("\n");
                //for (auto x : res) printf("%d ", x);
                //printf("\n");
            }
        }
        
    }
    printf("%d", cnt);

    return 0;
}