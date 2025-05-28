n, m = map(int, input().split())
ary = list(map(int, input().split()))
res, cur = 0, 0
i, j = 0, 0
for j in range(m):
    cur += ary[j]
while j < n:
    res = max(res, cur)
    j += 1
    if j == n:
        break
    cur += ary[j]
    cur -= ary[i]
    i += 1

print(res)