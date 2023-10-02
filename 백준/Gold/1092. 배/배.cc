#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(void) {
    int n, m, in, res = 0, cnt = 0, st = 0;
    multiset<int, greater<int>> s;
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in);
        s.insert(in);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &in);
        if (in > *s.begin()) {
            cout << -1;
            return 0;
        }
        v.push_back(in);
    }
    sort(v.begin(), v.end(), greater<int>());
    auto iter = s.begin();
    in = 0;
    while (1) {
        if (v[in] <= *iter && v[in]) {
            v[in] = 0;
            iter++;
            cnt++;
        }
        in++;
        if (in >= m) {
            if (cnt == m) {
                res++;
                break;
            }
            in = 0;
            res++;
            iter = s.begin();
        }        
        if (iter == s.end()) {
            in = 0;
            res++;
            iter = s.begin();
        }
    }
    cout << res;
    return 0;
}