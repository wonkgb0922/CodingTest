from math import *
n = int(input())
l = list(map(int, input().split()))
ary = [0 for i in range(n)]
cnt = 0
x = 0
for i in range(1, len(l)):
  ary[i] = max(ceil(log2(l[i - 1] / l[i])) + ary[i - 1], 0)
  cnt += ary[i]
print(cnt)