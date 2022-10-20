//피타고라스의 정리
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#pragma warning (disable:4996)

using namespace std;

int main(void){
    int x, y, z;
    
    vector<int> v;
    
    while (true)
    {
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0) break;
        v.clear();
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        sort(v.begin(), v.end());
        if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) printf("right\n");
        else printf("wrong\n");
        
    }
    
    return 0;
}