n = int(input())
ary = [i for i in range(1, n + 1)]

while len(ary) != 1:
  for i in range(len(ary) - 1, -1, -1):
    if i % 2 == 0:
      ary.pop(i)

if n == 1:
  print(1)
else:
  print(ary[0])