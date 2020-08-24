// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <boost/rational.hpp>

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

static constexpr ll flip(ll K, ll i) {
  ll res = i, count = 0;
  while (res < K) {
    res <<= 1;
    count++;
  }
  return count;
}

int main() {
  ll N, K;
  cin >> N >> K;

  boost::rational<ll> res;
  REP1(i, N) {
    boost::rational<ll> a(1, N * static_cast<ll>(pow(2, flip(K, i))));
    res += a;
  }
  cout << boost::rational_cast<double>(res) << endl;
  return 0;
}
