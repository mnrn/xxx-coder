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

struct solve {
  explicit solve(const vec<ull> &A) : A(A) { cout << exec(0, 1) << endl; }
  ull exec(ull depth, ull acc) {
    if (depth == A.size()) {
      return (acc & 1) ? 0 : 1;
    } else {
      return exec(depth + 1, acc * A[depth]) +
             exec(depth + 1, acc * (A[depth] - 1)) +
             exec(depth + 1, acc * (A[depth] + 1));
    }
  }
  vec<ull> A;
};

int main() {
  ull N;
  cin >> N;
  vec<ull> A(N);
  REP(i, N) cin >> A[i];
  solve res(A);
  return 0;
}
