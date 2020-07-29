import re

print ('AC' if re.match(r'\AA[a-z](?:[a-z]*C[a-z]*)[a-z]\Z', input()) else 'WA')  
