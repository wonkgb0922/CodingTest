list = [0 for i in range(46)]
def f(n):
    if list[n] != 0:
        return list[n]
    if n <= 2:
        return 1
    list[n] = f(n - 1) + f(n - 2)
    return list[n]

n = int(input())
print(f(n))