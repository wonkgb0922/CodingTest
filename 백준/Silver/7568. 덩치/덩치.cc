#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void){
    int n, a, b;
    vector<pair<int, int>> v;
    vector<int> res;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back(pair<int, int>(a, b));
    }
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if (v[i].first < v[j].first)
            {
                if (v[i].second < v[j].second)
                {
                   /* cout << "v[i] : " << i << " " <<v[i].first << " " << v[i].second << endl;
                    cout << "v[j] : " << j << " " << v[j].first << " " << v[j].second << endl;*/
                    cnt++;
                }
                            
            }
        }
        res.push_back(cnt);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", res[i]);
    }
	return 0;
    
}