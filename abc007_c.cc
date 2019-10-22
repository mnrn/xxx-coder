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
// constexpr auto mod = 1000000007;
using namespace std;

using pii = pair<int, int>;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr array<int, 4> dy = {0, 1, 0, -1};
constexpr array<int, 4> dx = {1, 0, -1, 0};
int sy, sx, gy, gx;
int R, C;
vector<vector<char>> c;
vector<vector<int>> d;

int bfs() {
  d[sy][sx] = 0;
  queue<pii> q;
  q.emplace(sx, sy);

  while (!q.empty()) {
    const auto xy = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      const int x = xy.first, y = xy.second;
      const int nx = x + dx[i], ny = y + dy[i];
      if (0 <= nx && nx < C && 0 <= ny && ny < R && c[ny][nx] == '.' &&
          d[ny][nx] == INF) {
        d[ny][nx] = d[y][x] + 1;
        q.emplace(nx, ny);
      }
    }
  }
  return d[gy][gx];
}

int main() {
  cin >> R >> C >> sy >> sx >> gy >> gx;
  sx--;
  sy--;
  gx--;
  gy--;
  c.resize(R);
  d.resize(R);
  REP(y, R) {
    c[y].resize(C);
    d[y].resize(C);
    REP(x, C) {
      cin >> c[y][x];
      d[y][x] = INF;
    }
  }
  cout << bfs() << endl;
  return 0;
}
