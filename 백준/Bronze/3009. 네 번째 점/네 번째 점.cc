#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#pragma warning (disable:4996)

using namespace std;

int main(void){
    int x, y;
    vector<pair<int, int>> v;
    vector<int> X;
    vector<int> Y;
    //int X[3], Y[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
    }
    int rx, ry;
    if (v[0].first == v[1].first) rx = v[2].first;
    else // 0과 1이 다를 때
    {
        if (v[1].first == v[2].first) rx = v[0].first;
        else rx = v[1].first;
    }
    if (v[0].second == v[1].second) ry = v[2].second;
    else // 0과 1이 다를 때
    {
        if (v[1].second == v[2].second) ry = v[0].second;
        else ry = v[1].second;
    }
    printf("%d %d", rx, ry);
    
    return 0;
}