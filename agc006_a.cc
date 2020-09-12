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
  string s, t;
  cin >> s >> t;

  vec<string> ss(N);
  string tmp;
  for (int i = N - 1; i >= 0; i--) {
    tmp = s[i] + tmp;
    ss[N - 1 - i] = tmp;
  }

  tmp.clear();
  vec<string> ts(N);
  for (int i = 0; i < N; i++) {
    tmp = tmp + t[i];
    ts[i] = tmp;
  }

  ll com = 0;
  for (int i = 0; i < N; i++) {
    if (ss[i] == ts[i]) {
      com = i + 1;
    }
  }
  const auto ans = s.length() + t.length() - com;
  cout << ans << endl;
  return 0;
}
