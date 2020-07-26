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
  using key_t = pair<const string, int>;
  int N;
  cin >> N;
  auto cmp = [](const key_t &x, const key_t &y) {
    return x.first < y.first || (!(y.first < x.first) && x.second > y.second);
  };
  map<key_t, int, decltype(cmp)> m(cmp);
  REP1(i, N) {
    int P;
    string S;
    cin >> S >> P;
    m[make_pair(S, P)] = i;
  }
  for (const auto &[k, v] : m) {
    cout << v << endl;
  }
  return 0;
}
