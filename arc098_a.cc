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
  int N;
  cin >> N;
  string S;
  cin >> S;

  vec<int> L(N);
  vec<int> R(N);
  L[0] = R[N - 1] = 0;

  for (int i = 1; i < N; i++) {
    L[i] = L[i - 1] + (S[i - 1] == 'W' ? 1 : 0);
  }
  for (int i = N - 1; i >= 1; i--) {
    R[i - 1] = R[i] + (S[i] == 'E' ? 1 : 0);
  }

  int answer = min(L[N - 1], R[0]);
  for (int i = 1; i < N - 1; i++) {
    answer = min(answer, L[i] + R[i]);
  }
  cout << answer << endl;
  return 0;
}
