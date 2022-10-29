#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(void) {
    int n, k;
    int s, e, end;
    int cnt = 0;
    vector<pair<int,int>> v;

    cin >> n;
    
    while (n--)
    {
        cin >> s >> e;

        v.push_back(pair<int, int>(s, e));
    }
    sort(v.begin(), v.end(), comp);
    end = v[0].second;
    cnt++;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first >= end)
        {
            cnt++;
            end = v[i].second;
        }
        
    }
    printf("%d", cnt);
    return 0;
}