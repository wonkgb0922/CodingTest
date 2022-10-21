#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#pragma warning (disable:4996)

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
struct Greater
{
    bool opearator(int a, int b)
    {
        return a < b;
    }
};
int main(void){
    int n;
    int dir, dis;
    int X, Y, x, y;
    int a = 0, b = 0, c = 0, d = 0;
    int res;
    vector<pair<int, int>> v;
    cin >> n;

    for (int i = 0; i < 6; i++)
    {
        cin >> dir >> dis;
        v.push_back(pair<int, int>(dir, dis));
    }

    for (auto it : v)
    {
        if (it.first == 1) a++;
        else if (it.first == 2) b++;
        else if (it.first == 3) c++;
        else d++;
    }
    if (a == 2 && c == 2) // 3131패턴
    {
        int i;
        for (i = 0; i < 6; i++)
        {
            if (v[i].first == 4) break;
        }
        Y = v[i].second;
        i++;
        if (i >= 6) i = i - 6;
        X = v[i].second;
        i+=2;
        if (i >= 6) i = i - 6;
        x = v[i].second;
        i++;
        if (i >= 6) i = i - 6;
        y = v[i].second;
    }
    else if (d == 2 && b == 2) // 4242패턴
    {
        int i;
        for (i = 0; i < 6; i++)
        {
            if (v[i].first == 3) break;
        }
        Y = v[i].second;
        i++;
        if (i >= 6) i = i - 6;
        X = v[i].second;
        i += 2;
        if (i >= 6) i = i - 6;
        x = v[i].second;
        i++;
        if (i >= 6) i = i - 6;
        y = v[i].second;
    }
    else if (a == 2 && d == 2) // 1414 패턴
    {
        int i;
        for (i = 0; i < 6; i++)
        {
            if (v[i].first == 2) break;
        }
        X = v[i].second;
        i++;
        if (i >= 6) i = i - 6;
        Y = v[i].second;
        i += 2;
        if (i >= 6) i = i - 6;
        y = v[i].second;
        i++;
        if (i >= 6) i = i - 6;
        x = v[i].second;
    }
    else if (b == 2 && c == 2) // 2323 패턴
    {
        int i;
        for (i = 0; i < 6; i++)
        {
            if (v[i].first == 1) break;
        }
        X = v[i].second;
        i++;
        if (i >= 6) i = i - 6;
        Y = v[i].second;
        i += 2;
        if (i >= 6) i = i - 6;
        y = v[i].second;
        i++;
        if (i >= 6) i = i - 6;
        x = v[i].second;
    }

    res = (X * Y - x * y) * n;
    printf("%d", res);
    
    
    return 0;
}