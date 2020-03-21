NR == 1 {
  N = $1
}
NR > 1 {
  e[$1, $2]++
  e[$2, $1]++
}
END {
  for (i = 1; i <= N; i++) {
    count = 0
    for (j = 1; j <= N; j++) {
      count += e[i, j]
    }
    print(count)
  }
}
