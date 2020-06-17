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
  ll H, W;
  cin >> H >> W;
  if (H == 1 || W == 1) {
    cout << 1 << endl;
    return 0;
  }

  ll answer = 0;
  for (ll y = 0; y < H; y++) {
    ll add = W / 2;
    if (W % 2 == 1 && y % 2 == 0) {
      add += 1;
    }
    answer += add;
  }
  cout << answer << endl;
  return 0;
}
