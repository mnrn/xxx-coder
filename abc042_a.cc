// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= int(a); --i)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, int(n) + 1)
#define RREP(i, n) RFOR(i, 0, n)
#define RREP1(i, n) RFOR(i, 1, int(n) + 1)
#define ALL(c) begin(c), end(c)

template <typename T> using vec = std::vector<T>;
using vi = vec<int>;
using vvi = vec<vi>;
using pii = std::pair<int, int>;
using ll = long long;
using ld = long double;
// constexpr auto mod = 1000000007;
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  vi lst{A, B, C};
  sort(ALL(lst));
  vi expected{5, 5, 7};
  cout << (lst == expected ? "YES" : "NO") << endl;

  return 0;
}
