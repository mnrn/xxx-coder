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

template <typename T> using vec = std::vector<T>;
using vi = vec<int>;
using ll = long long;
using ld = long double;
// constexpr auto mod = 1000000007;
using namespace std;

int main() {
  string s;
  cin >> s;
  const auto size = s.size();
  vi changed = {0, 0};
  REP(i, size) {
    if (s[i] != (i % 2 == 0 ? '0' : '1')) {
      changed[0]++;
    } else {
      changed[1]++;
    }
  }
  cout << min(changed[0], changed[1]) << endl;
  return 0;
}
