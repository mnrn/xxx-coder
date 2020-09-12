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

static constexpr ull anti_divisions(ull X, ull C, ull D) {
  const ull Y = X - (X / C) - (X / D);
  return Y + X / lcm(C, D);
}

int main() {
  ull A, B, C, D;
  cin >> A >> B >> C >> D;
  const ull B_ = anti_divisions(B, C, D);
  const ull A_ = anti_divisions(A - 1, C, D);
  cout << B_ - A_ << endl;
  return 0;
}
