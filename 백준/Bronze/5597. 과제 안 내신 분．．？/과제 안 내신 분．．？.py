a = [str(i) for i in range(1, 31)]
for i in range(28):
  b = input()
  a.remove(b)
for it in a:
  print(it)