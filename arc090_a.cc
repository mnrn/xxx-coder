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
  vec<ll> L(N), R(N);

  ll l, accl = 0;
  REP(i, N) {
    cin >> l;
    accl += l;
    L[i] = accl;
  }

  ll accr = 0;
  vec<ll> tmp(N);
  REP(i, N) cin >> tmp[i];
  reverse(ALL(tmp));
  REP(i, N) {
    accr += tmp[i];
    R[i] = accr;
  }
  reverse(ALL(R));

  ll answer = 0;
  REP(i, N) { answer = max(answer, L[i] + R[i]); }
  cout << answer << endl;
  return 0;
}
