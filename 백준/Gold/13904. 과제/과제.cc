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

int main(void) {
    int n;
    int d, w;
    int max = 0, sum = 0;
    vector<pair<int,int>> v;
    int ary[1001] = { 0 }, index;
    //int min = 1001, maxcap = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> d >> w;
        v.push_back(pair<int, int>(w, d));
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for (int i = 0; i < n; i++)
    {
        index = v[i].second;
        while (ary[index] != 0)
        {
            if (--index == 0) break;
        }
        if (index == 0) continue;
        //printf("%d %d %d\n", index, v[i].first, v[i].second);
        ary[index] = v[i].first;
        if (max < index) max = index;
    }
    for (int i = 1; i <= max; i++)
    {
        sum += ary[i];
    }
    printf("%d", sum);
    return 0;
}