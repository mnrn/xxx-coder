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

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> l(Q), r(Q);
  REP(i, Q) {
    cin >> l[i] >> r[i];
    // 0-based
    l[i]--;
    r[i]--;
  }

  vector<int> cs(N, 0);
  FOR(i, 1, N) {
    const auto T = S.substr(i - 1, 2);
    cs[i] = cs[i - 1] + ((T == "AC") ? 1 : 0);
  }
  REP(i, Q) { cout << cs[r[i]] - cs[l[i]] << endl; }

  return 0;
}
