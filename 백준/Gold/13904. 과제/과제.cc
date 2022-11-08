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
    int cnt = 0;
    int ary[1001] = { 0 };
    vector<pair<int, int>> v;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> d >> w;
        v.push_back(pair<int, int>(w, d));
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());

    for (int i = 0; i < n; i++)
    {
        int temp = v[i].second;
        while (ary[temp] != 0) temp--;
        if (temp > 0)
        {
            //printf("%d %d %d\n", v[i].second, temp, v[i].first);
            ary[temp] = v[i].first;
            cnt += v[i].first;
        }
    }
    printf("%d", cnt);

    return 0;
}