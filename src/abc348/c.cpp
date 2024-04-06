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
#define print_pair(pair) cout << "{}" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  int n;
  cin >> n;
  // vector<pair<int, int>> col_yum(n);
  // rep(i, 0, n) cin >> col_yum[i].second >> col_yum[i].first;
  // sort(col_yum.begin(), col_yum.end());
  map<int, int> col_yum{};
  rep(i, 0, n)
  {
    int yum, color;
    cin >> yum >> color;
    if (col_yum[color] == 0)
    {
      col_yum[color] = yum;
    }
    else if (col_yum[color] > yum)
    {
      col_yum[color] = yum;
    }
  }

  int min_yum = 0;
  for (auto it = col_yum.begin(); it != col_yum.end(); it++)
  {
    if (min_yum < it->second)
    {
      min_yum = it->second;
    }
  }

  cout << min_yum << endl;
  return 0;
}
