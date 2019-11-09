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

int main() {
  int n, q;
  cin >> n;
  vec<ll> S(n);
  REP(i, n) { cin >> S[i]; }
  cin >> q;
  vec<ll> T(q);
  REP(i, q) { cin >> T[i]; }
  ll answer = 0;
  REP(i, q) { answer += (binary_search(ALL(S), T[i]) ? 1 : 0); }
  cout << answer << endl;
  return 0;
}
