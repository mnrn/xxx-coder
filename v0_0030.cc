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

int n, s;

struct solve {
  solve() {
    dfs(0, 0, -1);
    cout << answer << endl;
  }
  void dfs(int acc, int depth, int from) {
    if (acc > s || depth > n) {
      return;
    }
    if (depth == n && acc == s) {
      answer++;
      return;
    }
    for (int i = from + 1; i < 10; i++) {
      dfs(acc + i, depth + 1, i);
    }
  }
  int answer = 0;
};

int main() {
  for (;;) {
    cin >> n >> s;
    if (n == 0 && s == 0) {
      break;
    }
    solve();
  }
  return 0;
}
