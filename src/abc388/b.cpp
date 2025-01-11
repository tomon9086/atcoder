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
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> tl(n, {0, 0});
  rep(i, 0, n) cin >> tl[i].first >> tl[i].second;

  rep(k, 1, d + 1)
  {
    int max = 0;
    rep(i, 0, n)
    {
      int w = tl[i].first * (tl[i].second + k);
      if (w > max)
      {
        max = w;
      }
    }
    cout << max << endl;
  }

  return 0;
}
