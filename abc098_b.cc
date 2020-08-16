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
  string S;
  cin >> N >> S;

  int ans = 0;
  set<char> L;
  for (int i = 0; i < N - 1; i++) {
    L.emplace(S[i]);
    set<char> R, res;
    for (int j = i + 1; j < N; j++) {
      R.emplace(S[j]);
    }
    set_intersection(ALL(L), ALL(R), inserter(res, res.end()));
    ans = max(ans, static_cast<int>(res.size()));
  }
  cout << ans << endl;
  return 0;
}
