n, m = map(int, input().split())
l = list(map(int, input().split()))
for i in range(m):
    a, b, c = map(int, input().split())
    if a == 1:
        l[b-1] = c
    elif a == 2:
        for j in range(b-1, c):
            l[j] = 1 - l[j]
    elif a== 3:
        for j in range(b-1, c):
            l[j] = 0
    else:
        for j in range(b-1, c):
            l[j] = 1

for i in l:
    print(i, end=' ')