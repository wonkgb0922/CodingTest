t = int(input())
while t:
    res = -999
    n = int(input())
    ary = list(map(int, input().split()))
    s = [0 for _ in range(n + 1)]
    s[0] = 0
    for i in range(1, len(s)):
        s[i] = s[i - 1] + ary[i - 1]
    
    for i in range(n):
        for j in range(n, i, -1):
            res = max(res, s[j] - s[i])
    print(res)
    t -= 1