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

static constexpr bool is_odd(ll n) { return n & 0x01 != 0; }
static constexpr bool is_multiple_of_4(ll n) { return n % 4 == 0; }

int main() {
  ll N;
  cin >> N;
  ll odd = 0, multi4 = 0;
  REP(i, N) {
    ll a;
    cin >> a;
    if (is_odd(a)) {
      odd++;
    } else if (is_multiple_of_4(a)) {
      multi4++;
    }
  }
  if (odd == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  const ll multi2not4 = N - odd - multi4;
  const ll not4chunk = odd + (multi2not4 > 0);
  cout << (multi4 >= not4chunk - 1 ? "Yes" : "No") << endl;
  return 0;
}
