// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <boost/lexical_cast.hpp>

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

struct solve {
  solve(int H, int W, const vec<vec<char>> &S, const vec<vec<int>> &C)
      : H(H), W(W), S(S), C(C) {
    exec();
  }
  ~solve() {
    REP(y, H) {
      REP(x, W) {
        cout << (C[y][x] == -1 ? '#' : boost::lexical_cast<char>(C[y][x]));
      }
      cout << endl;
    }
  }
  void exec() {
    REP(y, H) {
      REP(x, W) {
        if (S[y][x] == '#') {
          continue;
        }
        int cost = 0;
        REP(i, 8) {
          const int nx = x + dx[i], ny = y + dy[i];
          if (0 <= nx && nx < W && 0 <= ny && ny < H && S[ny][nx] == '#') {
            cost++;
          }
        }
        C[y][x] = cost;
      }
    }
  }
  int H, W;
  vec<vec<char>> S;
  vec<vec<int>> C;
  static constexpr array<int, 8> dx{-1, -1, -1, 0, 1, 1, 1, 0};
  static constexpr array<int, 8> dy{-1, 0, 1, 1, 1, 0, -1, -1};
};

int main() {
  int H, W;
  cin >> H >> W;
  vec<vec<char>> S(H, vec<char>(W));
  vec<vec<int>> C(H, vec<int>(W, -1));
  REP(y, H) {
    REP(x, W) { cin >> S[y][x]; }
  }
  solve res(H, W, S, C);
  return 0;
}
