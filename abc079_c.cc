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
  vec<int> ABCD;
  transform(ALL(S), back_inserter(ABCD),
            [](char c) { return boost::lexical_cast<int>(c); });
  const int A = ABCD[0];
  const int B = ABCD[1];
  const int C = ABCD[2];
  const int D = ABCD[3];

  if (A + B + C + D == 7) {
    cout << S[0] << "+" << S[1] << "+" << S[2] << "+" << S[3] << "=7" << endl;
  } else if (A + B + C - D == 7) {
    cout << S[0] << "+" << S[1] << "+" << S[2] << "-" << S[3] << "=7" << endl;
  } else if (A + B - C + D == 7) {
    cout << S[0] << "+" << S[1] << "-" << S[2] << "+" << S[3] << "=7" << endl;
  } else if (A + B - C - D == 7) {
    cout << S[0] << "+" << S[1] << "-" << S[2] << "-" << S[3] << "=7" << endl;
  } else if (A - B + C + D == 7) {
    cout << S[0] << "-" << S[1] << "+" << S[2] << "+" << S[3] << "=7" << endl;
  } else if (A - B + C - D == 7) {
    cout << S[0] << "-" << S[1] << "+" << S[2] << "-" << S[3] << "=7" << endl;
  } else if (A - B - C + D == 7) {
    cout << S[0] << "-" << S[1] << "-" << S[2] << "+" << S[3] << "=7" << endl;
  } else if (A - B - C - D == 7) {
    cout << S[0] << "-" << S[1] << "-" << S[2] << "-" << S[3] << "=7" << endl;
  }
  return 0;
}
