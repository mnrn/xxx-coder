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
  ll X;
  cin >> X;

  set<ll> x;
  constexpr ll CEIL = 1000;
  for (ll b = 1; b <= 100; b++) {
    for (ll p = 2; p < 10; p++) {
      const ll e = static_cast<ll>(pow(static_cast<ld>(b), static_cast<ld>(p)));
      if (e <= CEIL) {
        x.emplace(e);
      }
    }
  }
  auto it = lower_bound(ALL(x), X);
  if ((*it) != X)
    --it;
  cout << (*it) << endl;
  return 0;
}
