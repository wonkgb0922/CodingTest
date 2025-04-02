while True:
  a, b, c = map(int, input().split())

  a = [a, b, c]
  if a[0] == 0 and a[1] == 0 and a[2] == 0:
    break
  
  a.sort()
  if a[0] + a[1] > a[2]:
    if a[0] == a[1] == a[2]:
      print('Equilateral')
    elif a[0] != a[1] != a[2]:
      print('Scalene')
    else:
      print('Isosceles')
  else:
    print('Invalid')