#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int n, input;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    printf("%d", v[0] * v[n - 1]);

    

    return 0;
}