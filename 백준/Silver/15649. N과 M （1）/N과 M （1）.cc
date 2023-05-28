#include <stdio.h>
#include <iostream>

#pragma warning (disable:4996)

using namespace std;

int ary[9];
bool visited[9] = { false };
int n, m;

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", ary[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ary[cnt] = i;
            visited[i] = true;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(void) {
    cin >> n >> m;

    dfs(0);

    return 0;
}