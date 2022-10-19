#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#pragma warning (disable:4996)

using namespace std;

int main(void){
    int n, m, cnt = 0;
    string input;
    int temp;
    int b, e;
    set<string> v;

    cin >> input;

    temp = input.size();

    for (int i = 0; i < input.size(); i++)
    {
        b = 0;
        for (int j = 0; j < temp; j++)
        {
            v.insert(input.substr(b, input.size() - temp + 1));
           // cout << input.substr(b, input.size() - temp + 1) << endl;
            b++;
        }
        temp--;
    }

    printf("%d", v.size());
    

    return 0;
}