from queue import PriorityQueue
import sys
print = sys.stdout.write
input = sys.stdin.readline
n = int(input())
pq = PriorityQueue()

for i in range(n):
    req = int(input())
    if req == 0:
        if pq.empty():
            print('0\n')
        else:
            temp = pq.get()
            print(str(temp[1]) + '\n')
    else:
        pq.put((-req, req))