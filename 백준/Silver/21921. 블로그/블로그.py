n, x = map(int, input().split())
ary = [int(x) for x in input().split()]
S = [0]
res = 0
cnt = 0
for i in range(1, n + 1):
  S.append(S[i - 1] + ary[i - 1])
for i in range(n - x + 1):
  diff = S[i + x] - S[i]
  if res < diff:
    res = diff
    cnt = 1
  elif res == diff:
    cnt += 1
  
if res == 0:
  print("SAD")
else:
  print(res)
  print(cnt)