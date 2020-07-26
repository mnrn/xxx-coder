// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

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
  if (N < 10) {
    cout << N << endl;
    return 0;
  }

  const auto n = boost::lexical_cast<string>(N);
  const auto h = boost::lexical_cast<ll>(n.front());
  const auto d = n.size();

  for (int i = 1; i < d; i++) {
    if (n[i] != '9') {
      cout << (h - 1) + 9 * (d - 1);
      return 0;
    }
  }
  cout << h + 9 * (d - 1) << endl;
  return 0;
}
