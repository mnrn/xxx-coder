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

static constexpr ll INF = numeric_limits<ll>::max() / 2;

int main() {
  ll A, B, M;
  cin >> A >> B >> M;
  vec<ll> a(A), b(B);

  ll mina = INF, minb = INF;
  REP(i, A) {
    cin >> a[i];
    mina = min(mina, a[i]);
  }
  REP(i, B) {
    cin >> b[i];
    minb = min(minb, b[i]);
  }
  ll answer = mina + minb, x, y, c;
  REP(i, M) {
    cin >> x >> y >> c;
    answer = min(answer, a[x - 1] + b[y - 1] - c);
  }
  cout << answer << endl;

  return 0;
}
