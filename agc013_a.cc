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
  ll N;
  cin >> N;
  vec<ll> A(N);
  REP(i, N) cin >> A[i];

  ll res = 1;
  optional<int> global_grad;
  FOR(i, 1, N) {
    optional<int> local_grad;
    if (A[i - 1] < A[i]) {
      local_grad = -1;
    } else if (A[i - 1] > A[i]) {
      local_grad = 1;
    }
    if (!global_grad) {
      global_grad = local_grad;
    } else if (global_grad && local_grad && global_grad != local_grad) {
      res++;
      global_grad = nullopt;
    }
  }
  cout << res << endl;
  return 0;
}
