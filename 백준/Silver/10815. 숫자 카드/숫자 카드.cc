#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(void){
    int n, m, input, res;
    set<int> s;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &input);
        s.insert(input);
    }
    scanf("%d", &m);
    while(m--) {
        scanf("%d", &input);
        printf("%d ", s.count(input));
    }
    return 0;
}