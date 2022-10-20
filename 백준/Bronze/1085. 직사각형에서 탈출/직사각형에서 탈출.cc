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
    int w, h;

    cin >> x >> y >> w >> h;

    int dis = (w - x < h - y) ? w - x : h - y;
    if (dis > x) dis = x;
    if (dis > y) dis = y;
    
    printf("%d", dis);
    return 0;
}