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

static int watering(const vec<int> &h, vec<int> &f, int N) {
  bool is_changed = false;
  int res = 0;
  REP(i, N) {
    if (h[i] > f[i]) {
      if (!is_changed) {
        is_changed = true;
        res++;
      }
      f[i]++;
    } else {
      is_changed = false;
    }
  }
  return res;
}

int main() {
  int N;
  cin >> N;
  vec<int> h(N);
  REP(i, N) cin >> h[i];

  vec<int> f(N, 0);
  int res = 0;
  REP(i, 101) res += watering(h, f, N);
  cout << res << endl;
  return 0;
}
