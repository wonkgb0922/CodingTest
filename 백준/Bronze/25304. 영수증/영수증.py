x = int(input())
n = int(input())

for i in range(n):
  v, c = map(int, input().split())
  x -= v * c

if x:
  print('No')
else:
  print('Yes')