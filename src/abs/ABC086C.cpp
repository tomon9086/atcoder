#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define print_pair(pair) cout << "{}" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  ll n;
  cin >> n;

  ll pt = 0, px = 0, py = 0;
  rep(i, n)
  {
    ll t, x, y;
    cin >> t >> x >> y;

    bool possible = false;
    for (ll j = 0; j < t - pt; j += 2)
    {
      ll d = abs(x - px) + abs(y - py);
      // cout << t - pt << " " << d << " " << j << endl;

      if (t - pt == d + j)
      {
        possible = true;
        break;
      }
    }

    if (!possible)
    {
      cout << "No" << endl;
      return 0;
    }

    pt = t;
    px = x;
    py = y;
  }

  cout << "Yes" << endl;
  return 0;
}
