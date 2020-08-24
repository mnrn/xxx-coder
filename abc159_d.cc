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

static constexpr ll nc2(ll n) { return n <= 1 ? 0 : n * (n - 1) / 2; }

int main() {
  ll N;
  cin >> N;
  vec<ll> A(N);
  unordered_map<ll, ll> m;
  REP(i, N) {
    cin >> A[i];
    m[A[i]]++;
  }

  ll acc = 0;
  for (const auto &[_, v] : m) {
    acc += nc2(v);
  }

  REP(i, N) { cout << acc - (m[A[i]] - 1) << endl; }
  return 0;
}
