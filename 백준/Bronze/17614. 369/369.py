n = int(input())
res = 0
for i in range(1, n + 1):
  cnt = 0
  for j in str(i):
    if j in ['3', '6', '9']:
      cnt += 1

  res += cnt

print(res)