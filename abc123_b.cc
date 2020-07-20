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
using pii = std::pair<int, int>;
template <typename T> using vec = std::vector<T>;
using namespace std;

static inline constexpr int roundup(int val) { return 10 * ((val + 9) / 10); }

int main() {
  multimap<int, int> dishes;
  REP(i, 5) {
    int v;
    cin >> v;
    dishes.emplace(v % 10, v);
  }

  int answer = 0, count = 1;
  constexpr array<int, 10> numbers = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  for (const auto &k : numbers) {
    if (dishes.count(k) == 0) {
      continue;
    }
    auto range = dishes.equal_range(k);
    for (auto it = range.first; it != range.second; ++it) {
      if (count < 5) {
        answer += roundup(it->second);
        count++;
      } else {
        answer += it->second;
      }
    }
  }

  cout << answer << endl;
  return 0;
}
