m, n = map(int, input().split())
arr = [list(map(int, input().split())) for i in range(m)]
arr2 = [list(map(int, input().split())) for i in range(m)]
arr3 = [[arr[j][i] +arr2[j][i] for i in range(n)]for j in range(m)]
b = '\n'.join([' '.join(map(str, arr3[i])) for i in range(m)])
print(b)