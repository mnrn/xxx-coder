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

int main() {
  int N;
  cin >> N;

  queue<string> q;
  unordered_map<string, int> m;
  REP(i, N) {
    string W;
    cin >> W;
    q.emplace(W);
    m[W]++;
  }
  if (any_of(ALL(m), [](const auto &p) { return p.second > 1; })) {
    cout << "No" << endl;
    return 0;
  }

  char t = '\0';
  while (!q.empty()) {
    const auto w = q.front();
    if (t != '\0' && t != w.front()) {
      cout << "No" << endl;
      return 0;
    }
    q.pop();
    t = w.back();
  }
  cout << "Yes" << endl;
  return 0;
}
