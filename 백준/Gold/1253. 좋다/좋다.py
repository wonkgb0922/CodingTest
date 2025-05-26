n = int(input())
ary = list(map(int, input().split()))
ary.sort()
cnt = 0
for k in range(n):
  i = 0
  j = n - 1
  while i < j:
    if ary[i] +ary[j] == ary[k]:
      if i != k and j != k:
        cnt += 1
        break
      elif i == k:
        i += 1
      elif j == k:
        j -= 1
    elif ary[i] + ary[j] > ary[k]:
      j -= 1
    else:
      i += 1
print(cnt)
