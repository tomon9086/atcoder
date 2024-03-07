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

vector<ll> search(int n, int m, vector<vector<ll>> a, int initial_index)
{
  vector<bool> flags(n, false);
  vector<ll> ret(3, 0);

  flags.at(initial_index) = true;
  ret = a.at(initial_index);

  // cout << initial_index << ": ";
  // print_vec(ll, ret);

  rep(i, m - 1)
  {
    int absmax_i = -1;
    vector<ll> absmax_v(3, 0);
    rep(j, n)
    {
      if (flags.at(j))
      {
        continue;
      }

      if (abs(ret.at(0) + absmax_v.at(0)) +
              abs(ret.at(1) + absmax_v.at(1)) +
              abs(ret.at(2) + absmax_v.at(2)) <
          abs(ret.at(0) + a.at(j).at(0)) +
              abs(ret.at(1) + a.at(j).at(1)) +
              abs(ret.at(2) + a.at(j).at(2)))
      {
        absmax_v = a.at(j);
        absmax_i = j;
      }
    }

    if (absmax_i < 0)
    {
      // cout << abs(ret.at(0)) + abs(ret.at(1)) + abs(ret.at(2)) << endl;
      return ret;
    }

    ret.at(0) += absmax_v.at(0);
    ret.at(1) += absmax_v.at(1);
    ret.at(2) += absmax_v.at(2);
    flags.at(absmax_i) = true;

    // cout << absmax_i + 1 << ": ";
    // print_vec(ll, absmax_v);
  }

  // cout << abs(ret.at(0)) + abs(ret.at(1)) + abs(ret.at(2)) << endl;
  return ret;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(3));
  rep(i, n) cin >> a.at(i).at(0) >> a.at(i).at(1) >> a.at(i).at(2);

  ll absmax = 0;
  rep(k, n)
  {
    auto result = search(n, m, a, k);

    ll curr = abs(result.at(0)) + abs(result.at(1)) + abs(result.at(2));
    if (curr > absmax)
    {
      absmax = curr;
    }

    // cout << "result " << curr << ": ";
    // print_vec(ll, result);
  }

  cout << absmax << endl;

  return 0;
}
