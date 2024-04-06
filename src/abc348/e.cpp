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

map<int, vector<int>> edge{};

int d(int a, int b, int prev, int depth)
{
  if (a == b)
  {
    return depth;
  }

  int ret = -1;
  rep(i, 0, edge[a].size())
  {
    if (edge[a][i] == prev)
    {
      continue;
    }

    int result = d(edge[a][i], b, a, depth + 1);
    if (ret < result)
    {
      ret = result;
    }
  }

  return ret;
}

int main()
{
  int n;
  cin >> n;
  // vector<int> d(n, 0);
  // rep(i, 0, n - 1)
  // {
  //   int a, b;
  //   cin >> a >> b;
  //   d[a - 1]++;
  //   d[b - 1]++;
  // }

  rep(i, 0, n - 1)
  {
    int a, b;
    cin >> a >> b;
    edge[a - 1].push_back(b - 1);
  }

  rep(i, 0, n)
  {
    cout << d(0, i, -1, 0) << endl;
  }

  // vector<int> c(n);
  // rep(i, 0, n) cin >> c[i];

  // ll min_f = __LONG_LONG_MAX__;
  // rep(i, 0, n)
  // {
  //   ll f = c[i] * d[i];
  //   if (min_f > f)
  //   {
  //     min_f = f;
  //   }
  // }

  // cout << min_f << endl;
  return 0;
}
