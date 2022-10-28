#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int n, s, cnt = 0, rep;
int sum;
vector<int> v;
bool visited[20] = { false };
int ary[20] = { 0 };
int tempi = 0;

void ex(int m)
{
    if (m == rep)
    {
        for (int i = 0; i < rep; i++)
        {
            //printf("%d ", ary[i]);
            sum += ary[i];
        }
        if (sum == s) cnt++;
        sum = 0;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && tempi <= i)
        {
            tempi = i;
            visited[i] = true;
            ary[m] = v[i];
            ex(m + 1);
            tempi = 0;
            visited[i] = false;
        }
    }
}

int main(void) {
    int input;

    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    for (int i = 1; i <= n; i++)
    {
        rep = i;
        ex(0);
    }
    printf("%d", cnt);

    return 0;
}