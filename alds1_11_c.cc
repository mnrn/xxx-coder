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

using adjlst = vec<vec<int>>;
constexpr int INF = numeric_limits<int>::max() / 3;
int n;
adjlst adj;

void bfs() {
  vec<int> d(n, INF);
  queue<int> q;
  d[0] = 0;
  q.emplace(0);

  while (!q.empty()) {
    const auto u = q.front();
    q.pop();
    for (auto&& v: adj[u]) {
      if (d[v] == INF) {
        d[v] = d[u] + 1;
        q.emplace(v);
      }
    }
  }
  REP(i, n) {
    cout << (i + 1) << " ";
    cout << (d[i] == INF ? -1 : d[i]) << endl;
  }
}

int main() {
  int u, v, k;
  cin >> n;
  adj.resize(n);
  REP(i, n) {
    cin >> u >> k;
    adj[i].resize(k);
    REP(j, k) {
      cin >> v;
      adj[i].emplace_back(v - 1);
    }
  }
  bfs();
  return 0;
}
