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

constexpr auto NIL = make_pair(numeric_limits<int>::max() / 2, numeric_limits<int>::max() / 2);
constexpr array<int, 4> dx = {0, 1, 0, -1};
constexpr array<int, 4> dy = {-1, 0, 1, 0};
int H, W;
vec<vec<char>> s;
vec<vec<pii>> pi;

int path(int d, int x, int y, int b) {
  if (x == 0 && y == 0) {
    return W * H - d - b;
  }
  else {
    tie(x, y) = pi[y][x];
    return path(d + 1, x, y, b);
  }
}

int bfs() {
  int b = 0;
  REP(y, H) {
    REP(x, W) {
      pi[y][x] = NIL;
      if (s[y][x] == '#') {
        b++;
      }
    }
  }
  queue<pii> q;
  q.emplace(0, 0);

  while (!q.empty()) {
    const auto xy = q.front();
    q.pop();
    const auto x = xy.first, y = xy.second;
    REP(i, 4) {
      const int nx = x + dx[i], ny = y + dy[i];
      if (0 <= nx && nx < W && 0 <= ny && ny < H && s[ny][nx] != '#' && pi[ny][nx] == NIL) {
        pi[ny][nx] = make_pair(x, y);
        q.emplace(nx, ny);
      }
    }
  }
  if (pi[H-1][W-1] == NIL) {
    return -1;
  }
  else {
    return path(1, W-1, H-1, b);
  }
}

int main() {
  cin >> H >> W;
  s.resize(H);
  d.resize(H);
  pi.resize(H);
  REP(y, H) {
    s[y].resize(W);
    d[y].resize(W);
    pi[y].resize(W);
    REP(x, W) {
      cin >> s[y][x];
    }
  }
  cout << bfs() << endl;
  return 0;
}
