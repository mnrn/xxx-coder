import re

S = input()
m = re.search(r'\A([a-z]+)\1', S[:len(S) - 1])
print(len(m.group(0)))
