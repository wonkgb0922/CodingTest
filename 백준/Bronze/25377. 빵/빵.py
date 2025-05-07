n = int(input())
res = -1
for i in range(n):
  a, b = map(int, input().split())
  if a <= b:
    if res < 0 or res > b:
      res = b

print(res)