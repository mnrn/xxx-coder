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
  vec<int> ABC(3);
  cin >> ABC[0] >> ABC[1] >> ABC[2];

  sort(ALL(ABC));
  const auto sum = accumulate(ALL(ABC), 0);
  const auto A = ABC[2], B = ABC[1], C = ABC[0];

  const int diff = 3 * A - sum;
  const int res = ((diff & 1) ? (3 * (A + 1) - sum) : diff) / 2;
  cout << res << endl;
  return 0;
}
