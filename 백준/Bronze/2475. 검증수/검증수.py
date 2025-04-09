a = list((map(int, input().split())))
res = 0
for i in a:
  res += i**2

res %= 10
print(res)