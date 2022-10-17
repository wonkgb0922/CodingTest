#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n, m, input;
    int max = 0;
    vector<int> v;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (v[i] + v[j] + v[k] <= m)
                {
                    if (max < v[i] + v[j] + v[k]) max = v[i] + v[j] + v[k];
                }
            }
        }
    }
    printf("%d", max);
	return 0;
    
}