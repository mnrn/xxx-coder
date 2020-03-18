BEGIN {
  FS=""
}
{
  for (i = 1; i <= NF; i++) {
    count[$i]++
  }
  for (key in count) {
    if (count[key] % 2 != 0) {
      print "No"
      exit
    }
  }
  print "Yes"
}
