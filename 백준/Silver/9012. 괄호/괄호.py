n = int(input())
for i in range(n):
    s = input()
    st = []
    res = True
    for j in s:
        if j == '(':
            st.append(j)
        elif j == ')':
            if st:
                st.pop()
            else:
                res = False
                break

    if res and not st:
        print("YES")
    else:
        print("NO")