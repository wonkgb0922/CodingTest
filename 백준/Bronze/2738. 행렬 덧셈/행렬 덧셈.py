n, m = map(int, input().split())
a = [[0 for __ in range(m)] for _ in range(n)]
b = [[0 for __ in range(m)] for _ in range(n)]

for i in range(n):
  c = list(map(int, input().split()))
  for j in range(m):
    a[i][j] = c[j]

for i in range(n):
  c = list(map(int, input().split()))
  for j in range(m):
    b[i][j] = c[j]
  
for i in range(n):
  for j in range(m):
    print(a[i][j] + b[i][j], end=' ')
  print()