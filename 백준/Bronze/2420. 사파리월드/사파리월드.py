a, b = input().split()
a = int(a)
b = int(b)

c = a - b
if c < 0:
    c *= -1
print(c)