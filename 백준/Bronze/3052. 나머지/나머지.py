l = [0 for _ in range(42)]
cnt = 0
for _ in range(10):
  a = int(input())
  l[a % 42] += 1

for i in l:
  if i > 0:
    cnt += 1
print(cnt)