import sys

_ = int(input())
a = [int(x) for x in input().split()]

answer = sys.maxsize
for y in range(-100, 100 + 1):
    acc = 0
    for x in a:
        acc += (x - y) * (x - y)
    answer = min(answer, acc)
print(answer)
