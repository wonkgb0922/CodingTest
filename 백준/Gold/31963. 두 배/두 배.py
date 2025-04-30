import math
n = int(input())
l = list(map(int, input().split()))
ary = [0 for i in range(n)]
cnt = 0
x = 0
for i in range(1, len(l)):
  ary[i] = math.ceil(math.log2(l[i - 1] / l[i])) + ary[i - 1]
  cnt += ary[i]
print(max(cnt, 0))