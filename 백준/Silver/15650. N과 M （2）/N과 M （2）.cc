#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

bool visited[9] = { false };
int ary[9] = { 0 };
int n, m;

void dfs(int cnt)
{
    if (cnt >= m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", ary[i]);
            
        }
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                if (ary[cnt-1] < i || ary[cnt] == 0)
                {
                    visited[i] = true;
                    ary[cnt] = i;
                    dfs(cnt + 1);
                    visited[i] = false;
                }
            }
        }
    }
}

int main(void) {
    int ary[8] = { 0 };
    cin >> n >> m;
    
    dfs(0);

    return 0;
}