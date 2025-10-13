from collections import deque
n, l = map(int, input().split())  
d = deque()
cur = list(map(int, input().split()))

for i in range(n):
  while d and d[-1][0] > cur[i]:
    d.pop()
  d.append((cur[i], i))
  if d[0][1] <= i - l:
    d.popleft()
  print(d[0][0], end=' ')