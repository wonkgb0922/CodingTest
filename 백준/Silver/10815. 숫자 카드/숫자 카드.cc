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
    int n, m, input, res;
    set<int> s;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &input);
        s.insert(input);
    }
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &input);
        printf("%d ", s.count(input));
    }
    

	return 0;
    
}