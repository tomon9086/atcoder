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
  int h, w, q;
  cin >> h >> w;
  vector<vector<int>> x(h, vector<int>(w, 0));
  rep(i, 0, h) rep(j, 0, w)
  {
    if (j > 0)
    {
      x[i][j] = x[i][j - 1];
    }

    int a;
    cin >> a;

    x[i][j] += a;
  }
  cin >> q;

  // rep(i, 0, x[0].size())
  // {
  //   print_vec(int, x[i]);
  // }

  rep(_, 0, q)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int sum = 0;
    rep(i, a - 1, c)
    {
      sum += x[i][d - 1] - (b > 1 ? x[i][b - 2] : 0);
    }

    cout << sum << endl;
  }

  return 0;
}
