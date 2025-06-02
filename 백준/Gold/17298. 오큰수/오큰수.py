n = int(input())
ary = list(map(int, input().split()))
st = []
ans = [-1 for i in range(n)]
for i in range(n):
  if not st or ary[st[-1]] > ary[i]:
    st.append(i)
  else:
    while st and ary[st[-1]] < ary[i]:
      ans[st.pop()] = ary[i]
    st.append(i)
print(*ans)