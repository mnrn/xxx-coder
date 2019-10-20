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

ll gcd(ll a, ll b) { return a < b ? gcd(b, a) : b == 0 ? a : gcd(b, a % b); }

ll solve(const vector<ll> &A, int i, int N) {
  return i + 1 == N ? gcd(A[N - 2], A[N - 1]) : gcd(A[i], solve(A, i + 1, N));
}

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) { cin >> A[i]; }

  const ll answer = solve(A, 0, N);
  cout << answer << endl;
  return 0;
}
