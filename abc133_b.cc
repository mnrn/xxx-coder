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
using pii = std::pair<int, int>;
using namespace std;

int main() {
  ld N, D;
  cin >> N >> D;
  vec<vec<ld>> X(N, vec<ld>(D));
  REP(i, N) REP(j, D) cin >> X[i][j];

  int answer = 0;
  set<pii> uos;
  REP(i, N) {
    REP(j, N) {
      if (i == j || uos.count(make_pair(i, j)) > 0 ||
          uos.count(make_pair(j, i)) > 0) {
        continue;
      }
      const ld d =
          sqrt(inner_product(ALL(X[i]), X[j].begin(), 0, plus<>(),
                             [](ld x, ld y) { return (x - y) * (x - y); }));
      uos.emplace(i, j);
      if (d == nearbyint(d)) {
        answer++;
      }
    }
  }
  cout << answer << endl;
  return 0;
}
