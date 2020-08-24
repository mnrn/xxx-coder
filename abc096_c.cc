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

constexpr array<int, 4> dy = {0, 1, 0, -1};
constexpr array<int, 4> dx = {1, 0, -1, 0};

void solve(const vec<vec<char>> &s, int H, int W) {
  bitset<50 * 50> stamped;
  REP(y, H) {
    REP(x, W) {
      if (s[y][x] == '.') {
        continue;
      }
      REP(i, 4) {
        const auto nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < W && 0 <= ny && ny < H && s[ny][nx] == '#') {
          stamped.set(y * W + x);
          stamped.set(ny * W + nx);
        }
      }
    }
  }

  REP(y, H) {
    REP(x, W) {
      if (s[y][x] == '#' && !stamped[y * W + x]) {
        cout << "No" << endl;
        return;
      }
    }
  }
  cout << "Yes" << endl;
}

int main() {
  int H, W;
  cin >> H >> W;
  vec<vec<char>> s(H, vec<char>(W));
  REP(y, H) REP(x, W) cin >> s[y][x];

  solve(s, H, W);
  return 0;
}
