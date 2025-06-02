n = int(input())

cur = 1
st = []
ans = ''
res = True
for i in range(n):
  t = int(input())
  while cur <= t:
    st.append(cur)
    cur += 1
    ans += '+'
  if not len(st) or st[-1] < t:
    print("NO")
    res = False
    break
  while len(st) and st[-1] >= t:
    st.pop()
    ans += '-'
if res:
  print('\n'.join(ans))