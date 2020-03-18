S = input()

pat0 = 0  # 010101010...
pat1 = 0  # 101010101...

for i, c in enumerate(S):
    if i % 2 == 0:
        if c == '0':
            pat0 += 1
        else:
            pat1 += 1
    else:
        if c == '0':
            pat1 += 1
        else:
            pat0 += 1

N = len(S)
print(min(N - pat0, N - pat1))
