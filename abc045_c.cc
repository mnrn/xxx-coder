// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

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
  string S;
  cin >> S;
  const size_t N = S.size();

  vec<string> xss;
  for (int i = 0; i < (1 << (N - 1)); i++) {
    string xs;
    for (int j = 0; j < N; j++) {
      xs.push_back(S[j]);
      if ((i >> j) & 0x01) {
        xs.push_back('+');
      }
    }
    xss.emplace_back(xs);
  }

  vec<string> res;
  ll answer = 0;
  for (auto&& xs : xss) {
    boost::algorithm::split(res, xs, boost::is_any_of("+"));
    vec<ll> ts;
    transform(ALL(res), back_inserter(ts), [](const string& s){ return stoll(s); });
    answer += accumulate(ALL(ts), 0ll);
  }
  cout << answer << endl;
  return 0;
}
