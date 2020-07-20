import sequtils, strutils

proc getInt() : int =
  parseInt(readLine(stdin))

proc getInts() : seq[int] = 
  readLine(stdin).split().map(parseInt)

let
  A = getInt()
  B = getInt()
  C = getInt()
  X = getInt()

var answer = 0
for i in 0..<A+1:
  for j in 0..<B+1:
    for k in 0..<C+1:
      if 500 * i + 100 * j + 50 * k == X:
        answer+=1

echo answer
