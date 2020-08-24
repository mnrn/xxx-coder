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

static inline ll manhattan(ll x1, ll x2, ll y1, ll y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
  ll N, M;
  cin >> N >> M;
  vec<pair<ll, ll>> students(N), checkpoints(M);
  REP(i, N) {
    ll a, b;
    cin >> a >> b;
    students[i] = make_pair(a, b);
  }
  REP(i, M) {
    ll c, d;
    cin >> c >> d;
    checkpoints[i] = make_pair(c, d);
  }
  REP(i, N) {
    ll near = numeric_limits<ll>::max(), res = 0;
    REP(j, M) {
      const ll d = manhattan(students[i].first, checkpoints[j].first,
                             students[i].second, checkpoints[j].second);
      if (d < near) {
        near = d;
        res = j + 1;
      }
    }
    cout << res << endl;
  }
  return 0;
}
