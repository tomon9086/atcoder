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
  int h, w, n;
  cin >> h >> w >> n;

  vector<vector<int>> z_diff(h, vector<int>(w, 0));

  rep(_, 0, n)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    z_diff[a - 1][b - 1]++;
    if (d < w)
      z_diff[a - 1][d]--;
    if (c < h)
      z_diff[c][b - 1]--;
    if (c < h && d < w)
      z_diff[c][d]++;
  }

  vector<vector<int>> z(h, vector<int>(w, 0));

  rep(i, 0, h) rep(j, 0, w)
  {
    if (j > 0)
      z_diff[i][j] += z_diff[i][j - 1];
  }

  rep(i, 0, h) rep(j, 0, w)
  {
    z[i][j] = z_diff[i][j];
    if (i > 0)
      z[i][j] += z[i - 1][j];
  }

  rep(i, 0, h)
  {
    rep(j, 0, w) cout << z[i][j] << " ";
    cout << endl;
  }

  return 0;
}
