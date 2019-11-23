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

ll N, Q;
string s;
vec<char> t, d;

template <typename Comp> bool simulate(ll pos, ll threshold, Comp comp) {
  REP(i, Q) {
    if (s[pos] == t[i]) {
      pos += ((d[i] == 'L') ? -1 : 1);
    }
  }
  return comp(pos, threshold);
}

template <typename Comp> ll search(ll ok, ll ng, ll threshold, Comp comp) {
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    (simulate(mid, threshold, comp) ? ok : ng) = mid;
  }
  return ok;
}

int main() {
  cin >> N >> Q >> s;
  t.resize(Q);
  d.resize(Q);
  REP(i, Q) { cin >> t[i] >> d[i]; }

  const ll l = search(-1, N, 0, less<ll>());
  const ll r = search(N, -1, N - 1, greater<ll>());

  cout << max(0ll, r - l - 1ll) << endl;
  return 0;
}
