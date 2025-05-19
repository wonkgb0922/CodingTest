import sys
input = sys.stdin.readline
n, m = map(int, input().split())
ary = [int(x) for x in input().split()]
cnt = [0 for _ in range(m)]
res = 0; t = 0
cnt[0] = 1
for i in range(n):
    t = (t + ary[i]) % m
    res += cnt[t]
    cnt[t] += 1
print(res)