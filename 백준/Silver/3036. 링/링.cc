#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int gcd(int a, int b)
{
    if (a % b) return gcd(b, a % b);
    return b;
}

int main(void) {
    int n, input, a, b;
    int r;
    vector<int> v;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> input;
        //v.push_back(input);
        if (i == 0) r = input;
        else
        {
            printf("%d/%d\n", r / gcd(r, input), input / gcd(r, input));
        }
    }
    //r = v[0];
    /*for (int i = 1; i < v.size(); i++)
    {
        printf("%d/%d\n", r / gcd(r, v[i]), v[i] / (gcd(r, v[i])));
    }
    */
    return 0;
}