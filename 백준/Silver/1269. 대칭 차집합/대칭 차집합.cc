#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#pragma warning (disable:4996)

using namespace std;

int main(void){
    int n, m, cnt = 0;
    int input;
    set<int> v, res;

    scanf("%d %d", &n, &m);

    while (n--)
    {
        cin >> input;
        v.insert(input);
    }
    //sort(v.begin(), v.end());
    while (m--)
    {
        cin >> input;
        if (v.find(input) == v.end())
        {
            v.insert(input);
        }
        else v.erase(input);
    }
    printf("%d", v.size());
    

    return 0;
}