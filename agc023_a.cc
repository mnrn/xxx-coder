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
  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) { cin >> A[i]; }

  vector<ll> cs(N + 1, 0);
  cs[0] = 0;
  for (int i = 1; i <= N; i++) {
    cs[i] = cs[i - 1] + A[i - 1];
  }
  map<ll, ll> m;
  for (int i = 0; i <= N; i++) {
    m[cs[i]] = m[cs[i]] + 1;
  }
  ll answer = 0;
  for (const auto &kv : m) {
    const auto v = kv.second;
    answer += v * (v - 1) / 2;
  }
  cout << answer << endl;
  return 0;
}
