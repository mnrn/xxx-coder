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
  constexpr auto SELECTED = -1;

  array<array<ll, 3>, 3> A;
  REP(i, 3) {
    REP(j, 3) { cin >> A[i][j]; }
  }
  ll N;
  cin >> N;
  REP(i, N) {
    ll B;
    cin >> B;
    REP(i, 3) {
      REP(j, 3) {
        if (A[i][j] == B) {
          A[i][j] = SELECTED;
        }
      }
    }
  }

  // Row0
  if (A[0][0] == SELECTED && A[1][0] == SELECTED && A[2][0] == SELECTED) {
    cout << "Yes" << endl;
  }
  // Row1
  else if (A[0][1] == SELECTED && A[1][1] == SELECTED && A[2][1] == SELECTED) {
    cout << "Yes" << endl;
  }
  // Row2
  else if (A[0][2] == SELECTED && A[1][2] == SELECTED && A[2][2] == SELECTED) {
    cout << "Yes" << endl;
  }
  // Col0
  else if (A[0][0] == SELECTED && A[0][1] == SELECTED && A[0][2] == SELECTED) {
    cout << "Yes" << endl;
  }
  // Col1
  else if (A[1][0] == SELECTED && A[1][1] == SELECTED && A[1][2] == SELECTED) {
    cout << "Yes" << endl;
  }
  // Col2
  else if (A[2][0] == SELECTED && A[2][1] == SELECTED && A[2][2] == SELECTED) {
    cout << "Yes" << endl;
  }
  // Diagonal0
  else if (A[0][0] == SELECTED && A[1][1] == SELECTED && A[2][2] == SELECTED) {
    cout << "Yes" << endl;
  }
  // Diagonal1
  else if (A[0][2] == SELECTED && A[1][1] == SELECTED && A[2][0] == SELECTED) {
    cout << "Yes" << endl;
  }
  // Nothing
  else {
    cout << "No" << endl;
  }
  return 0;
}
