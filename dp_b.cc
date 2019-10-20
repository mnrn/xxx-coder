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
using ld = long double;
// constexpr auto mod = 1000000007;
using namespace std;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> h(N);
  REP(i, N) { cin >> h[i]; }

  constexpr ll INF = numeric_limits<ll>::max() / 3;
  vector<ll> dp(N, INF);
  dp[0] = 0;
  dp[1] = dp[0] + abs(h[0] - h[1]);
  REP(i, N) {
    REP1(j, K) {
      if (i + j < N) {
        dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
      }
    }
  }
  cout << dp[N - 1] << endl;
  return 0;
}
