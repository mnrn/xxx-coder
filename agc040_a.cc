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
  string S;
  cin >> S;

  const ll N = S.size();
  vec<ll> L(N + 1, 0);
  for (ll i = 0; i < N; i++) {
    if (S[i] == '<') {
      L[i + 1] = L[i] + 1;
    }
  }
  vec<ll> R(N + 1, 0);
  for (ll i = N - 1; i >= 0; i--) {
    if (S[i] == '>') {
      R[i] = R[i + 1] + 1;
    }
  }
  ll res = 0;
  REP(i, N + 1) res += max(L[i], R[i]);
  cout << res << endl;
  return 0;
}
