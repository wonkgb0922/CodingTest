#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int main(void){
    
    int n, m, cnt = 0;
    string input;
    vector<string> v, res;
    scanf("%d %d", &n, &m);

    while (n--)
    {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    while (m--)
    {
        cin >> input;
        if (binary_search(v.begin(), v.end(), input))
            res.push_back(input);
        
    }
    sort(res.begin(), res.end());
    printf("%d\n", res.size());
    for (auto x : res)
        cout << x << "\n";


    return 0;
}