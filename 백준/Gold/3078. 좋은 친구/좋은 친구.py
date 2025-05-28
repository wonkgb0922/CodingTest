import sys
input = sys.stdin.readline

n, k = map(int, input().split())
ary = [len(input()) for _ in range(n)]
i, j = 0, 0
res = 0
cnt = [0 for _ in range(22)]

for j in range(k + 1):
    cnt[ary[j]] += 1

while i < n:
    res += cnt[ary[i]] - 1
    cnt[ary[i]] -=1
    i += 1
    if j < n - 1:
        j += 1
        cnt[ary[j]] += 1
print(res)