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
  vec<vec<int>> c(3, vec<int>(3));
  REP(i, 3) REP(j, 3) cin >> c[i][j];

  for (int b1 = 0; b1 <= 100; b1++) {
    for (int b2 = 0; b2 <= 100; b2++) {
      for (int b3 = 0; b3 <= 100; b3++) {
        if (c[0][0] - b1 == c[1][0] - b2 && c[1][0] - b2 == c[2][0] - b3 &&
            c[0][1] - b1 == c[1][1] - b2 && c[1][1] - b2 == c[2][1] - b3 &&
            c[0][2] - b1 == c[1][2] - b2 && c[1][2] - b2 == c[2][2] - b3) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
