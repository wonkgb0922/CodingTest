n = int(input())
for _ in range(n):
    x, s = input().split()
    x = int(x)
    for it in s:
        print(it * x, end='')
    print()