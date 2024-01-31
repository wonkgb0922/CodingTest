#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int n, k, i;
    string s, res = "";
    stack<char> st;
    cin >> n >> k >> s;
    for (i = 0; i < n;) {
        if (st.empty() || st.top() >= s[i]) {
            st.push(s[i]);
            i++;
        }
        else {
            k--;
            st.pop();
        }
        if (k <= 0) break;
    }
    if (k <= 0) {
        for (; i < n; i++)
            st.push(s[i]);
    }
    else {
        while (k-- > 0 && !st.empty()) {
            st.pop();
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}