#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <memory.h>

using namespace std;

int dp[10000][2] = { 0, }, n;
vector<int> v;
multimap<int, int> mm;
bool visited[10000];

int sol(int idx, int d) {
    if (dp[idx][d] > 0) return dp[idx][d];

    auto rg = mm.equal_range(idx);

    visited[idx] = true;
    if (d) {
        for (auto& it = rg.first; it != rg.second; it++) {
            if (visited[it->second]) continue;
            auto rg2 = mm.equal_range(it->second);
            visited[it->second] = true;
            for (auto& it2 = rg2.first; it2 != rg2.second; it2++) {
                if(!visited[it2->second])
                    dp[idx][d] += max(sol(it2->second, 0), sol(it2->second, 1));
            }
            visited[it->second] = false;
        }
        dp[idx][d] += v[idx];
    }
    else {
        for (auto& it = rg.first; it != rg.second; it++) {
            if(!visited[it->second])
                dp[idx][d] += max(sol(it->second, 1), sol(it->second, 0));
        }
    }
    visited[idx] = false;
    return dp[idx][d];
}

int main(void) {
    int in1, in2, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in1);
        v.push_back(in1);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &in1, &in2);
        mm.insert({ in1 - 1,in2 - 1 });
        mm.insert({ in2 - 1,in1 - 1 });
    }
    in1 = 2;
    while (in1--) {
        memset(visited, false, sizeof(visited));
        res = max(res, sol(0, in1));
        //cout << sol(0, in1) << endl;
    }
    cout << res;
    return 0;
}