import re

A, B = [int(x) for x in input().split()]
S = input()
print ('Yes' if re.search(r'\A\d{{{}}}-\d{{{}}}\Z'.format(A, B), S) else 'No') 
