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
    int n, k;
    int input;
    vector<int> v;
    vector<int> r;
    int cnt = 0, temp = 0;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++)
    {
        //printf("%d %d\n", v[i] - v[i - 1], i - 1);
        r.push_back(v[i] - v[i - 1]);
    }
    sort(r.begin(), r.end());
    for (int i = 0; i < n - k; i++)
    {
        cnt += r[i];
    }
    printf("%d", cnt);

    return 0;
}