n,x = map(int, input().split())
res = -1
for i in range(n):
  s, t = map(int, input().split())
  if s + t > x:
    continue
  res = max(res, s)
print(res)  