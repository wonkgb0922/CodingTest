from queue import PriorityQueue

pq = PriorityQueue()
n = int(input())
for i in range(n):
    t = int(input())
    pq.put(t)
res = 0
while len(pq.queue) > 1:
    a = pq.get()
    b = pq.get()
    res += a + b
    pq.put(a + b)
print(res)