#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
#include <set>
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
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> xy_i(n);
  rep(i, 0, n)
  {
    cin >> xy_i[i].first.first >> xy_i[i].first.second;
    xy_i[i].second = i;
  }
  rep(i, 0, n)
  {
    int max_rr = -1;
    int max_i = -1;
    rep(j, 0, n)
    {
      if (i == j)
      {
        continue;
      }

      auto xy0 = xy_i[i].first;
      auto xy1 = xy_i[j].first;
      int rr = (xy1.first - xy0.first) * (xy1.first - xy0.first) + (xy1.second - xy0.second) * (xy1.second - xy0.second);
      // cout << max_rr << ", " << rr << endl;
      if (max_rr < rr)
      {
        max_rr = rr;
        max_i = xy_i[j].second;
      }
    }

    cout << max_i + 1 << endl;
  }

  return 0;
}
