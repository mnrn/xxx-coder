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
// using i32 = int32_t;
// using i64 = int64_t;
// using u64 = uint64_t;
// using f64 = double;
template <typename T> using vec = std::vector<T>;
using pii = std::pair<int, int>;
using namespace std;

constexpr bool check(ll R, ll B, ll x, ll y, ll k) {
  return R - k >= 0 && B - k >= 0 &&
         k <= (((R - k) / (x - 1)) + ((B - k) / (y - 1)));
}

int main() {
  ll R, B, x, y;
  cin >> R >> B >> x >> y;
  ll ok = 0, ng = min(R, B) + 1;
  while (ok + 1 < ng) {
    ll mid = ok + (ng - ok) / 2;
    (check(R, B, x, y, mid) ? ok : ng) = mid;
  }
  cout << ok << endl;
  return 0;
}
