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
  ll N, M;
  cin >> N >> M;
  vec<ll> P(N);
  REP(i, N) { cin >> P[i]; }
  P.emplace_back(0);

  vec<ll> Q((N + 1) * (N + 1));
  REP(i, N + 1) {
    REP(j, N + 1) { Q[i * N + j] = P[i] + P[j]; }
  }
  sort(ALL(Q));

  ll answer = -1;
  REP(i, (N + 1) * (N + 1)) {
    if (Q[i] <= M) {
      const auto lb = lower_bound(ALL(Q), M - Q[i] + 1) - 1;
      answer = max(answer, Q[i] + *lb);
    }
  }
  cout << answer << endl;

  return 0;
}
