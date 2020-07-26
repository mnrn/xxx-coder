// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= int(a); --i)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, int(n) + 1)
#define RREP(i, n) RFOR(i, 0, n)
#define RREP1(i, n) RFOR(i, 1, int(n) + 1)
#define ALL(c) begin(c), end(c)

int _ = (
#ifndef LOCAL
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false),
#endif
    std::cout.precision(10), std::cout.setf(std::ios::fixed));

using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T> using vec = std::vector<T>;
using namespace std;

int main() {
  string S;
  cin >> S;

  const int N = S.size();
  vec<string> x;
  string s;
  for (int i = 0; i < N;) {
    s = S.substr(i, 1);
    if (!x.empty() && s == x.back()) {
      s = S.substr(i, 2);
      i += 2;
    } else {
      i++;
    }
    x.emplace_back(s);
  }
  int answer = x.size();
  if (x.size() >= 2 && x[answer - 1] == x[answer - 2]) {
    answer--;
  }
  cout << answer << endl;
  return 0;
}
