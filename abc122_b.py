import re

m = re.findall(r'[ATCG]+', input())
print(max([len(x) for x in m]) if m else '0')
