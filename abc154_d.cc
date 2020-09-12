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

static constexpr ld expected(ld x) { return (x + 1.0) * x * 0.5 / x; }

int main() {
  ll N, K;
  cin >> N >> K;
  vec<ll> p(N), acc(N);
  ll t = 0;
  REP(i, N) {
    cin >> p[i];
    t += p[i];
    if (i >= K) {
      t -= p[i - K];
    }
    acc[i] = t;
  }
  ll vmax = 0, upper = 0;
  for (ll i = 0; i < N; i++) {
    if (acc[i] > vmax) {
      vmax = acc[i];
      upper = i;
    }
  }
  ld ans = 0;
  for (ll i = upper - K + 1; i <= upper; i++) {
    if (i >= 0 && i < N) {
      ans += expected(p[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
