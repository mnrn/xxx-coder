import sys

N, _ = map(int, input().split())
D = input().split()

answer = sys.maxsize
for x in range(N, 100000):
    s = str(x)
    if all([y not in s for y in D]):
        answer = min(answer, x)
print(answer)
