#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, ary[50], res = 0;
    bool isMinus = false, flag = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", ary + i);
        if (ary[i] < 0) isMinus = !isMinus;
    }
    sort(ary, ary + n, greater<>());
    for (int i = 0; i < n; i++) {
        if (ary[i] > 1) {
            if (i + 1 < n && ary[i + 1] > 1) {
                res += ary[i] * ary[i + 1];
                i++;
            }
            else
                res += ary[i];
        }
        else if (ary[i] == 1) res += ary[i];
        else if (ary[i] == 0) {
            if (isMinus) flag = true;
        }
        else {
            if (flag) {
                flag = false;
                isMinus = false;
            }
            else {
                if (isMinus) {
                    res += ary[i];
                    isMinus = false;
                }
                else {
                    res += ary[i] * ary[i + 1];
                    i++;
                }
            }
        }
    }
    printf("%d", res);

    return 0;
}