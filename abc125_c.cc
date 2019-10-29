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
template <typename T> using vec = std::vector<T>;
using pii = std::pair<int, int>;
using namespace std;

ll gcd(ll a, ll b) { return a < b ? gcd(b, a) : b == 0 ? a : gcd(b, a % b); }

int main() {
  ll N;
  cin >> N;
  vec<ll> A(N);

  REP(i, N) { cin >> A[i]; }

  vec<ll> L(N + 1);
  L[0] = 0;
  for (ll i = 0; i < N; i++) {
    L[i + 1] = gcd(L[i], A[i]);
  }
  vec<ll> R(N + 1);
  R[N] = 0;
  for (ll i = N; i >= 1; i--) {
    R[i - 1] = gcd(R[i], A[i - 1]);
  }

  ll answer = -1;
  for (ll i = 0; i < N; i++) {
    answer = max(answer, gcd(L[i], R[i + 1]));
  }
  cout << answer << endl;

  return 0;
}
