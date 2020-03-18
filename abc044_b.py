w = input()
d = {c: w.count(c) for c in w}
print("Yes" if all(d[k] % 2 == 0 for k in d) else "No")
