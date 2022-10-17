#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    int con;
    int sum, res = 0;
    vector<int> v;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        sum = 0;
        v.clear();
        con = i;
        while (con > 0)
        {
            v.push_back(con % 10);
            con /= 10;
        }
        for (auto x : v)
        {
            sum += x;
        }
        if (sum + i == n)
        {
            res = i;
            break;
        }
    }
    printf("%d", res);
	return 0;
    
}