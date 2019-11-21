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
  ll N, X;
  cin >> N >> X;
  vec<ll> w(N);
  REP(i, N) { cin >> w[i]; }

  vec<ll> f(1 << (N / 2));
  for (int i = 0; i < 1 << (N / 2); i++) {
    ll t = 0;
    for (int j = 0; j < (N / 2); j++) {
      t += ((i >> j) & 0x01) ? w[j] : 0;
    }
    f[i] = t;
  }

  vec<ll> b(1 << (N - N / 2));
  for (int i = 0; i < 1 << (N - N / 2); i++) {
    ll t = 0;
    for (int j = 0; j < (N - N / 2); j++) {
      t += ((i >> j) & 0x01) ? w[N / 2 + j] : 0;
    }
    b[i] = t;
  }
  sort(ALL(b));

  ll answer = 0;
  for (int i = 0; i < 1 << (N / 2); i++) {
    const auto p = equal_range(ALL(b), X - f[i]);
    answer += distance(p.first, p.second);
  }
  cout << answer << endl;

  return 0;
}
