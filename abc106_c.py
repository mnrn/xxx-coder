import re

m = re.match(r'\A(1*)([1-9]*)\Z', input())
print('1' if len(m.group(1)) >= int(input()) else m.group(2)[0])
