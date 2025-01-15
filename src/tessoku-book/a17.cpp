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

const int INF = 1e7;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n - 1), b(n - 2);
  rep(i, 0, n - 1) cin >> a[i];
  rep(i, 0, n - 2) cin >> b[i];

  vector<pair<int, int>> weight(n, {INF, -1});
  rep(i, 0, n)
  {
    if (i == 0)
    {
      weight[i] = {0, -1};
      continue;
    }

    int w_a = weight[i - 1].first + a[i - 1];
    int w_b = i > 1 ? weight[i - 2].first + b[i - 2] : INF;
    if (w_a <= w_b)
    {
      weight[i] = {w_a, i - 1};
    }
    else
    {
      weight[i] = {w_b, i - 2};
    }
  }

  // rep(i, 0, n) print_pair(weight[i]);

  vector<size_t> route;
  size_t next_i = n - 1;
  while (true)
  {
    if (next_i == -1)
      break;

    route.push_back(next_i);
    next_i = weight[next_i].second;
  }

  reverse(route.begin(), route.end());
  // print_vec(size_t, route);

  cout << route.size() << endl;
  rep(i, 0, route.size()) cout << route[i] + 1 << " ";
  cout << endl;

  return 0;
}
