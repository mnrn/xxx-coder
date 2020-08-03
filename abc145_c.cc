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
  ll N;
  cin >> N;
  vec<pair<ld, ld>> p(N);
  REP(i, N) {
    ll x, y;
    cin >> x >> y;
    p[i] = make_pair(x, y);
  }
  vec<ll> q(N);
  iota(ALL(q), 0);
  ld answer = 0;
  ll d = 0;
  do {
    for (ll i = 0; i < N - 1; i++) {
      answer += hypot(p[q[i + 1]].first - p[q[i]].first,
                      p[q[i + 1]].second - p[q[i]].second);
    }
    d++;
  } while (next_permutation(ALL(q)));
  answer /= static_cast<ld>(d);
  cout << answer << endl;
  return 0;
}
