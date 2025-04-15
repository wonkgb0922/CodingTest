s = input()

res = 0
for it in s:
    if it in 'ABC':
        res += 3
    elif it in 'DEF':
        res += 4
    elif it in 'GHI':
        res += 5
    elif it in 'JKL':
        res += 6
    elif it in 'MNO':
        res += 7
    elif it in 'PQRS':
        res += 8
    elif it in 'TUV':
        res += 9
    else:
        res += 10
print(res)