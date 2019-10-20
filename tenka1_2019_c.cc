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
  string S;
  cin >> N >> S;

  vector<int> b(N, 0), w(N, 0);
  FOR(i, 1, N) {
    b[i] = b[i - 1] + ((S[i - 1] == '#') ? 1 : 0);
    w[N - i - 1] = w[N - i] + (S[N - i] == '.' ? 1 : 0);
  }

  int answer = numeric_limits<int>::max();
  REP(i, N) { answer = min(answer, b[i] + w[i]); }
  cout << answer << endl;
  return 0;
}
