t = int(input())

for _ in range(t):
    h, w, n = map(int, input().split())
    x = n // h
    if n % h:
        x += 1
    y = n % h
    if y == 0:
        y = h
    print(y, end='')
    if x < 10: print('0', end='')
    print(x)