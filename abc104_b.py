import re

print ('AC' if re.match(r'\AA[a-z]+C[a-z]+\Z', input()) else 'WA')  
