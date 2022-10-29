#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int main(void) {
    int n, k;
    int input;
    int cnt = 0;
    vector<int> v;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    for(int i = n-1; i >= 0;)
    {
        if (v[i] > k)
        {
            i--;
            continue;
        }
        k -= v[i];
        cnt++;
        if (k == 0) break;
        
    }
    
    printf("%d", cnt);
    return 0;
}