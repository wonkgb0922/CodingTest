ary = [int(input()) for i in range(10)]
S = [0 for _ in range(114)]
res = 0
for i in range(1, 11):
  S[i] = S[i - 1] + ary[i - 1]
  res = S[i]
  if res == 100:
    break
  elif res > 100:
    if res - 100 > 100 - S[i - 1]:
      res = S[i - 1]
    break
print(res)
