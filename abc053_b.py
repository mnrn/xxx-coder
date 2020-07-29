import re

S = input()
m = re.search(r'A[A-Z]*Z', S)
print(len(m.group(0)))
