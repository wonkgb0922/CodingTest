n, k = map(int, input().split())
ary = list(map(int, input().split()))

i, j =  0, n - 1
cnt = 0
ary.sort()
while i < j:
    if ary[i] + ary[j] <= k:
        cnt += 1
        i += 1
        j -= 1
    elif ary[i] + ary[j] > k:
        j -= 1

print(cnt)