import re

S = input()
K = int(input())

m = re.match(r'\A(1+)([1-9]*)\Z', S)
if m:
    print('1' if len(m.group(1)) >= K else m.group(2)[0])
else:
    print(S[0])
