#include <stdio.h>
#include <iostream>

using namespace std;

bool visited[9];
int ary[9], n, m;

void dfs(int cnt)
{
    if (cnt >= m) {
        for (int i = 0; i < m; i++)
            printf("%d ", ary[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (cnt == 0 || ary[cnt - 1] < i) {
                visited[i] = true;
                ary[cnt] = i;
                dfs(cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int main(void) {
    cin >> n >> m;
    dfs(0);
    return 0;
}