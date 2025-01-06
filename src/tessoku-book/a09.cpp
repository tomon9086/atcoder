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

  vector<vector<int>> z(h, vector<int>(w, 0));

  rep(_, 0, n)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    rep(i, a - 1, c)
    {
      rep(j, b - 1, d)
      {
        z[i][j] += 1;
      }
    }
  }

  rep(i, 0, h)
  {
    rep(j, 0, w) cout << z[i][j] << " ";
    cout << endl;
  }

  return 0;
}
