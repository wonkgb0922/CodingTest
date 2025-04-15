s = input()
l = [0 for _ in range(26)]
for it in s:
    l[ord(it)-97] += 1

for i in l:
    print(i, end=' ')
    