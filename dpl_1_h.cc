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

constexpr ll INF = numeric_limits<ll>::max();

int main() {
  ll N, W;
  cin >> N >> W;
  vec<ll> w(N), v(N);
  REP(i, N) { cin >> v[i] >> w[i]; }

  vec<pair<ll, ll>> f(1 << (N / 2));
  REP(i, 1 << (N / 2)) {
    ll sw = 0, sv = 0;
    REP(j, N / 2) {
      if ((i >> j) & 0x01) {
        sw += w[j];
        sv += v[j];
      }
    }
    f[i] = make_pair(sw, sv);
  }
  sort(ALL(f));
  size_t m = 1;
  FOR(i, 1, 1 << (N / 2)) {
    if (f[m - 1].second < f[i].second) {
      f[m++] = f[i];
    }
  }

  ll answer = 0;
  REP(i, 1 << (N - (N / 2))) {
    ll sw = 0, sv = 0;
    REP(j, N - (N / 2)) {
      if ((i >> j) & 0x01) {
        sw += w[N / 2 + j];
        sv += v[N / 2 + j];
      }
    }
    if (sw <= W) {
      ll tv =
          (lower_bound(f.begin(), next(f.begin(), m), make_pair(W - sw, INF)) -
           1)
              ->second;
      answer = max(answer, sv + tv);
    }
  }
  cout << answer << endl;
  return 0;
}
