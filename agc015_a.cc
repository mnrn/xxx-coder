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

static constexpr ll solve(const ll N, const ll A, const ll B) {
  const ll M = N - 2;
  const ll first = A * M;
  const ll last = B * M;
  return last - first + 1;
}

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  if (A > B) {
    cout << 0 << endl;
  } else if (N == 1) {
    cout << (A == B ? 1 : 0) << endl;
  } else if (N == 2) {
    cout << (A == B ? 0 : 1) << endl;
  } else {
    cout << solve(N, A, B) << endl;
  }
  return 0;
}
