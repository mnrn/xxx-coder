import re

m = re.findall(r'[ATCG]+', input())
if m:
    print(max([len(x) for x in m]))
else:
    print('0')
