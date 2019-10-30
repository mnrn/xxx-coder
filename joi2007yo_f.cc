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

int a, b, n, gx, gy;
unordered_set<int> intersections;
constexpr array<int, 2> dx = {0, 1};
constexpr array<int, 2> dy = {1, 0};

struct solve {
  solve() {
    dfs(0, 0);
    cout << acc << endl;
  }

  void dfs(int x, int y) {
    if (x == gx && y == gy) {
      acc++;
    }
    REP(i, 2) {
      const int nx = x + dx[i], ny = y + dy[i];
      if (0 <= nx && nx < a && 0 <= ny && ny < b &&
          (intersections.count(a * ny + nx) <= 0)) {
        dfs(nx, ny);
      }
    }
  }
  int acc = 0;
};

int main() {
  cin >> a >> b >> n;
  gx = a - 1, gy = b - 1;
  REP(i, n) {
    int x, y;
    cin >> x >> y;
    intersections.emplace(a * (y - 1) + (x - 1));
  }
  solve();
  return 0;
}
