n, k = map(int, input().split())
ary = list(map(int, input().split()))
S = [0]; [S.append(S[-1] + x) for x in ary]

res = []
for i in range(k, n + 1):
  res.append(S[i]- S[i - k])
print(max(res))