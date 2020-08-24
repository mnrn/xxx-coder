// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <boost/lexical_cast.hpp>

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

bool ok(int N, int M, const vec<int> &s, const vec<int> &c, const string &t) {
  if (t.length() != N) {
    return false;
  }
  for (int j = 0; j < M; j++) {
    if (t[s[j] - 1] != boost::lexical_cast<char>(c[j])) {
      return false;
    }
  }
  return true;
}

string solve(int N, int M, const vec<int> &s, const vec<int> &c) {
  for (int i = 0; i < 1000; i++) {
    string t = boost::lexical_cast<string>(i);
    if (ok(N, M, s, c, t)) {
      return t;
    }
  }
  return string("-1");
}

int main() {
  int N, M;
  cin >> N >> M;
  vec<int> s(M), c(M);
  REP(i, M) { cin >> s[i] >> c[i]; }
  cout << solve(N, M, s, c) << endl;
  return 0;
}
