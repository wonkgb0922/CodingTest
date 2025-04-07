n, m = map(int, input().split())
a = []
for i in range(n):
  c = list(map(int, input().split()))
  a.append(c)
for i in range(n):
  c = list(map(int, input().split()))
  for j in range(m):
    print(a[i][j] + c[j], end=' ')
  print()