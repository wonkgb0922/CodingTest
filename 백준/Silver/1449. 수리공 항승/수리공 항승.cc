#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int n, l;
    int input;
    int temp;
    int cnt = 0;
    vector<int> v;

    cin >> n >> l;
    while (n--)
    {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    temp = l;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - v[i-1] + 1 <= temp)
        {
            //printf("%d %d\n", v[i - 1], v[i]);
            temp -= v[i] - v[i-1];
        }
        else
        {
            cnt++;
            temp = l;
        }
    }
    cnt++;
    printf("%d", cnt);
    return 0;
}