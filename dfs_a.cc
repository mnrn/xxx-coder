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

const vector<int> dx = {-1, 0, 1, 0};
const vector<int> dy = {0, -1, 0, 1};

int H, W;
int sx, sy, gx, gy;
vector<vector<char>> c;
vector<vector<int>> visited;

void dfs(int x, int y) {
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    const int nx = x + dx[i];
    const int ny = y + dy[i];
    if (0 <= nx && nx < W && 0 <= ny && ny < H && c[ny][nx] != '#' &&
        visited[ny][nx] == 0) {
      dfs(nx, ny);
    }
  }
}

int main() {
  cin >> H >> W;
  c.resize(H);
  visited.resize(H);
  REP(h, H) {
    c[h].resize(W);
    visited[h].resize(W);
    REP(w, W) {
      cin >> c[h][w];
      if (c[h][w] == 's') {
        sx = w;
        sy = h;
      } else if (c[h][w] == 'g') {
        gx = w;
        gy = h;
      }
      visited[h][w] = 0;
    }
  }
  dfs(sx, sy);
  cout << (visited[gy][gx] == 1 ? "Yes" : "No") << endl;
  return 0;
}
