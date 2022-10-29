#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int n, k;
    int s, e;
    int j;
    int cnt = 0;
    vector<pair<int,int>> v;
    priority_queue<int, vector<int>, greater<int>> q;


    cin >> n;
    while (n--)
    {
        cin >> s >> e;
        v.push_back(pair<int, int>(s, e));
    }
    sort(v.begin(), v.end());
    q.push(v[0].second);

    for (int i = 1; i < v.size(); i++)
    {
        q.push(v[i].second);
        if (q.top() <= v[i].first) q.pop();
    }

    
    printf("%d", q.size());
    return 0;
}