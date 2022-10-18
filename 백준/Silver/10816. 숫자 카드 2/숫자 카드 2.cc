#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int main(void){
    int n, m, input;
    vector<int> s;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &input);
        s.push_back(input);
    }
    sort(s.begin(), s.end());
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &input);
        printf("%d ", upper_bound(s.begin(), s.end(), input) - lower_bound(s.begin(), s.end(), input));
    }
	return 0;
}