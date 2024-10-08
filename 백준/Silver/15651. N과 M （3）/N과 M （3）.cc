#include <stdio.h>
#include <iostream>

using namespace std;

int ary[8], n, m;

void dfs(int cnt)
{
    if (cnt >= m) {
        for (int i = 0; i < m; i++)
            printf("%d ", ary[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        ary[cnt] = i;
        dfs(cnt + 1);
    }
}

int main(void) {
    cin >> n >> m;
    dfs(0);
    return 0;
}