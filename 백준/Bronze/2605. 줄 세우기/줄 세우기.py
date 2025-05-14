n = int(input())
l = list(map(int, input().split()))
ary = [i+1 for i in range(n)]

for i in range(n):
  ary.remove(i + 1)
  ary.insert(i - l[i], i + 1)

for i in range(n):
  print(ary[i], end=' ')