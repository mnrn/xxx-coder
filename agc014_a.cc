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

ll solve(ll A, ll B, ll C, ll d) {
  if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
    return d;
  } else if (A == B && B == C) {
    return -1;
  } else {
    const ll A2 = A / 2, B2 = B / 2, C2 = C / 2;
    return solve(B2 + C2, C2 + A2, A2 + B2, d + 1);
  }
}

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  cout << solve(A, B, C, 0) << endl;
  return 0;
}
