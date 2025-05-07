n, c = map(int, input().split())
a = b = n
for i in range(c):
  x, y = map(int, input().split())
  if x >= a or y >= b:
    continue
  if b * (a - x) <= a * (b - y):
    a = x
  else:
    b = y

print(a * b)