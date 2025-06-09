n = int(input())
st = []
while n:
    q = int(input())
    if q == 0:
        st.pop()
    else:
        st.append(q)
    n -= 1
print(sum(st))