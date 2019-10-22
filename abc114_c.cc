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
using ld = long double;
// constexpr auto mod = 1000000007;
using namespace std;

ll N;
const string _753 = "753";

ll dfs(const string &s) {
  if (!s.empty() && stoll(s) > N) {
    return 0;
  }
  ll ret = all_of(ALL(_753),
                  [&s](const char &c) { return s.find(c) != string::npos; })
               ? 1
               : 0;
  for (auto &&c : _753) {
    ret += dfs(s + c);
  }
  return ret;
}

int main() {
  cin >> N;
  cout << dfs("") << endl;
  return 0;
}
