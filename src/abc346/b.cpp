#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, begin, end) for (ll i = (begin); i < (end); i++)
#define print_pair(pair) cout << "{}" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  int w, b;
  cin >> w >> b;

  int mw = w % 7;
  int mb = b % 5;

  if (
      // 0
      (mw == 0 && mb == 0) ||
      // 1
      (mw == 1 && mb == 0) ||
      (mw == 0 && mb == 1) ||
      // 2
      (mw == 1 && mb == 1) ||
      (mw == 2 && mb == 0) ||
      // 3
      (mw == 2 && mb == 1) ||
      (mw == 1 && mb == 2) ||
      // 4
      (mw == 2 && mb == 2) ||
      (mw == 3 && mb == 1) ||
      // 5
      (mw == 3 && mb == 2) ||
      (mw == 2 && mb == 3) ||
      // 6
      (mw == 4 && mb == 2) ||
      (mw == 3 && mb == 3) ||
      // 7
      (mw == 4 && mb == 3) ||
      (mw == 5 && mb == 2) ||
      // 8
      (mw == 5 && mb == 3) ||
      (mw == 4 && mb == 4) ||
      // 9
      (mw == 5 && mb == 4) ||
      (mw == 6 && mb == 3) ||
      // 10
      (mw == 5 && mb == 5) ||
      (mw == 6 && mb == 4) ||
      // 11
      (mw == 6 && mb == 5) ||
      (mw == 7 && mb == 4))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
