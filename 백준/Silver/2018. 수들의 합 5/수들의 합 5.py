n = int(input())
i = 1; j = 1
sum = 1
cnt = 1
while j != n:
  if sum == n:
    cnt += 1
    j += 1
    sum += j
  elif sum < n:
    j += 1
    sum += j
  else:
    sum -= i
    i += 1

print(cnt)