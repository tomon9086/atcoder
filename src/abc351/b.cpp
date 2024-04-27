#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, begin, end) for (ll i = (begin); i < (end); i++)
#define print_pair(pair) cout << "{" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<vector<char>> a(n, vector<char>(n));

  rep(y, 0, n) rep(x, 0, n)
  {
    cin >> a[x][y];
  }
  rep(y, 0, n) rep(x, 0, n)
  {
    char curr;
    cin >> curr;

    if (a[x][y] != curr)
    {
      cout << y + 1 << " " << x + 1 << endl;
    }
  }

  return 0;
}
