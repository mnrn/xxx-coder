import sequtils, strutils

proc getInt() : int =
  parseInt(readLine(stdin))

proc getInts() : seq[int] = 
  readLine(stdin).split().map(parseInt)
