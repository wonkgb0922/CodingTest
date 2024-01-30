#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
multimap<int, int> g;
bool visited[2000];

bool dfs(int idx, int cnt)
{
    if (cnt == 4) return true;
    auto rg = g.equal_range(idx);

    for (auto& it = rg.first; it != rg.second; it++) {
        if (!visited[it->second]) {
            visited[it->second] = true;
            if (dfs(it->second, cnt + 1)) return true;
            visited[it->second] = false;
        }
    }
    return false;
}

int main() {
    int in, in2, res = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &in, &in2);
        g.insert({ in ,in2 });
        g.insert({ in2 ,in });
    }
    for (int i = 0; i < n; i++) {
        visited[i] = true;
        if (dfs(i, 0)) {
            res = 1;
            break;
        }
        visited[i] = false;
    }
    cout << res;
    return 0;
}