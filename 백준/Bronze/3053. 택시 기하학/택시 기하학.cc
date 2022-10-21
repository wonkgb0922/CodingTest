#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define PI 3.141592653589793

#pragma warning (disable:4996)

using namespace std;

int main(void){
    
    int n;

    cin >> n;
    
    printf("%.6lf\n%.6lf", n * n * PI, n*n*2.0);
    
    
    return 0;
}