#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

int cnt[26];

int main(void) {
    char c, in;
    while (1) {
        scanf("%c", &c);
        if (c == '#') break;
        memset(cnt, 0, sizeof(cnt));
        while (1) {
            scanf("%c", &in);
            if (in == '\n') break;
            if (in >= 'A' && in <= 'Z') cnt[in - 'A']++;
            else if (in >= 'a' && in <= 'z') cnt[in - 'a']++;
        }
        printf("%c %d\n", c, cnt[c - 'a']);
    }
    return 0;
}