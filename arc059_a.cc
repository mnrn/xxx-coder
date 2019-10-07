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
  int N;
  cin >> N;
  vector<int> a(N);
  REP(i, N) cin >> a[i];

  int answer = numeric_limits<int>::max() / 3;
  for (int y = -100; y <= 100; y++) {
    int sum = accumulate(
        ALL(a), 0, [y](int acc, int x) { return acc + (x - y) * (x - y); });
    answer = min(answer, sum);
  }
  cout << answer << endl;

  return 0;
}
