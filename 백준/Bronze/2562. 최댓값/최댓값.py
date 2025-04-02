max = 0
maxi = 0
for i in range(9):
  a = int(input())
  if max < a:
    max = a
    maxi = i + 1
print(max)
print(maxi)