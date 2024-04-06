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
  int h, w, n;
  cin >> h >> w;
  vector<vector<char>> a(w, vector<char>(h));
  rep(j, 0, h) rep(i, 0, w) cin >> a[i][j];
  cin >> n;
  vector<pair<pair<int, int>, int>> xy_e(n);
  rep(i, 0, n) cin >> xy_e[i].first.first >> xy_e[i].first.second >> xy_e[i].second;

  cout << "Hello, world!" << endl;
  return 0;
}
