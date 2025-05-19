n = int(input())
ary = [int(x) for x in input().split()]
S = [0]
res = 0
for i in range(1, n + 1):
    S.append(S[i - 1] + ary[i - 1])
for i in range(1, n + 1):
  res += ary[i - 1] * (S[n] - S[i]) % 1000000007
  res %= 1000000007

print(res)