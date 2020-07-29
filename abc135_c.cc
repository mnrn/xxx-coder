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
  vec<ll> A(N + 1), B(N);
  REP(i, N + 1) cin >> A[i];
  REP(i, N) cin >> B[i];

  ll answer = 0;
  REP(i, N) {
    if (A[i] < B[i]) {
      const ll rest = min(B[i] - A[i], A[i + 1]);
      A[i + 1] -= rest;
      answer += A[i] + rest;
    } else {
      answer += B[i];
    }
  }
  cout << answer << endl;
  return 0;
}
