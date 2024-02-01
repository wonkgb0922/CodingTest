#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, S[100001];

int main() {
    int in, res = 0, i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        scanf("%d", &in);
        S[i + 1] = S[i] + in;
    }
    for (i = 1, j = 0; i <= n;) {
        if (S[i] - S[j] < m) i++;
        else {
            if (res == 0 || res > i - j) res = i - j;
            j++;
        }
    }
    cout << res;

    return 0;
}