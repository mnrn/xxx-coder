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

int H, W;
vec<vec<char>> S;
vec<vec<int>> C;

void solve() {
  REP(y, H) {
    REP(x, W) {
      if (S[y][x] == '#') {
        continue;
      }
      int cost = 0;
      for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
          const int nx = x + dx, ny = y + dy;
          if (0 <= nx && nx < W && 0 <= ny && ny < H && S[ny][nx] == '#') {
            cost++;
          }
        }
      }
      C[y][x] = cost;
    }
  }
  REP(y, H) {
    REP(x, W) {
      if (C[y][x] == -1) {
        cout << '#';
      }
      else {
        cout << C[y][x];
      }
    }
    cout << endl;
  }
}

int main() {
  cin >> H >> W;
  S.resize(H);
  C.resize(H);
  REP(y, H) {
    S[y].resize(W);
    C[y].resize(W);
    REP(x, W) {
      cin >> S[y][x];
      C[y][x] = -1;
    }
  }
  solve();
  return 0;
}
