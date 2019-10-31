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

struct island {
  ll weight;
  ll limit;
  island() = default;
  island(ll weight, ll limit) : weight(weight), limit(limit) {}
  bool operator < (const island& rhs) const {
    return limit > rhs.limit;  // NOTE: REVERSE for min priority queue.
  }
};

int main() {
  for(;;) {
    ll n;
    cin >> n;
    if (n == 0) {
      break;
    }
    priority_queue<island> q;
    REP(i, n) {
      ll weight, limit;
      cin >> weight >> limit;
      q.emplace(weight, limit);
    }

    ll acc = 0;
    while (!q.empty()) {
      const auto island = q.top();
      if (acc + island.weight <= island.limit) {
        acc += island.weight;
        q.pop();
      }
      else {
        break;
      }
    }
    cout << (q.empty() ? "Yes" : "No") << endl;
  }
  return 0;
}
