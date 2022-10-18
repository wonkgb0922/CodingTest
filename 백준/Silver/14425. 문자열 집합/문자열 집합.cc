#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main(void){
    int n, m, cnt = 0;
    string input;
    set<string> s;
    cin >> n >> m;
    while(n--)
    {
        cin >> input;
        s.insert(input);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> input;
        if (s.count(input)) cnt++;
    }
    printf("%d", cnt);
    

	return 0;
    
}