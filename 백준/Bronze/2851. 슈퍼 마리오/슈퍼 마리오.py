ary = [int(input()) for i in range(10)]
S = [0 for _ in range(114)]
res = 0
for i in range(1, 11):
  S[i] = S[i - 1] + ary[i - 1]
  if S[i] == 100:
    res = S[i]
    break
  elif S[i] > 100:
    if S[i] - 100 <= 100 - res:
      res = S[i]
    break
  res = S[i]
print(res)
