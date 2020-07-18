// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

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
  string S;
  cin >> S;

  int answer = numeric_limits<int>::max();
  for (int i = 0; i < S.size() - 2; i++) {
    const auto sub = S.substr(i, 3);
    answer = min(answer, abs(753 - boost::lexical_cast<int>(sub)));
  }
  cout << answer << endl;
  return 0;
}
