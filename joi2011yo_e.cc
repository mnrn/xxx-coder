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

constexpr ll INF = numeric_limits<ll>::max() / 2;
constexpr array<int, 4> dx = {0, 1, 0, -1};
constexpr array<int, 4> dy = {-1, 0, 1, 0};
int H, W, N;
vec<vec<char>> c;
vec<vec<ll>> d;
map<int, pair<int, int>> m;

ll bfs(int sx, int sy, int gx, int gy) {
  REP(y, H) {
    REP(x, W) {
      d[y][x] = INF;
    }
  }
  d[sy][sx] = 0;
  queue<pii> q;
  q.emplace(sx, sy);

  while (!q.empty()) {
    const auto xy = q.front();
    q.pop();
    const int x = xy.first, y = xy.second;
    REP(i, 4) {
      const int nx = x + dx[i], ny = y + dy[i];
      if (0 <= nx && nx < W && 0 <= ny && ny < H && c[ny][nx] != 'X' && d[ny][nx] == INF) {
        d[ny][nx] = d[y][x] + 1;
        q.emplace(nx, ny);
      }
    }
  }
  return d[gy][gx];
}

int main() {
  cin >> H >> W >> N;
  c.resize(H);
  d.resize(H);
  REP(y, H) {
    c[y].resize(W);
    d[y].resize(W);
    REP(x, W) {
      cin >> c[y][x];
      if (c[y][x] == 'S') {
        m[0] = make_pair(x, y);
      }
      else if ('1' <= c[y][x] && c[y][x] <= '9') {
        m[c[y][x] - '0'] = make_pair(x, y);
      }
    }
  }
  ll answer = 0;
  for (int i = 0; i < N; i++) {
    const auto s = m[i];
    const auto g = m[i + 1];
    answer += bfs(s.first, s.second, g.first, g.second);
  }
  cout << answer << endl;
  return 0;
}
