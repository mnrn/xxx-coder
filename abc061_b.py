import sqlite3
from contextlib import closing
N, M = [int(x) for x in input().split()]

with closing(sqlite3.connect(':memory:')) as con:
    c = con.cursor()
    c.execute('create table Edges (src int, dst int)')

    for _ in range(M):
        a, b = [int(x) for x in input().split()]
        c.execute('insert into Edges values (?, ?)', (a, b))

    for i in range(N):
        query = 'select count(*) from Edges where src = ? or dst = ?'
        for row in c.execute(query, (i + 1, i + 1)):
            print(row[0])
