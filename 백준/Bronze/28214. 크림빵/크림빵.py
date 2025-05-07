n, k, p = map(int, input().split())
ary = list(map(int, input().split()))
res = n
for i in range(0, n*k, k):
  cnt = 0
  for j in range(i, i + k):
    if ary[j] == 0:
      cnt += 1
    if cnt >= p:
      res -=1
      break

print(res)