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
  int N, K;
  cin >> N >> K;
  vector<int> D(K);
  for (auto &&Di : D) {
    cin >> Di;
  }
  vector<int> S = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  set<int> T;
  set_difference(ALL(S), ALL(D), inserter(T, T.end()));
  const int UN = 10 * N;
  FOR(i, N, UN) {
    set<int> U;
    auto t = i;
    while (t) {
      U.emplace(t % 10);
      t = t / 10;
    }
    if (all_of(ALL(U), [&T](const int u) { return T.count(u) > 0; })) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
