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

static inline constexpr ld temp(int T, int x) { return T - x * 0.006; }

int main() {
  ld N, T, A;
  cin >> N >> T >> A;

  int answer = 0;
  ld near = numeric_limits<int>::max();
  REP1(i, N) {
    ld H;
    cin >> H;
    const ld t = temp(T, H);
    const ld d = abs(t - A);
    if (d < near) {
      answer = i;
      near = d;
    }
  }
  cout << answer << endl;
  return 0;
}
