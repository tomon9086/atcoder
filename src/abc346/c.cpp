#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a.at(i);

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  // print_vec(ll, a);
  // cout << a.size() << endl;

  ll sum = (k * (k + 1)) / 2;
  rep(i, 0, a.size())
  {
    if (a.at(i) <= k)
    {
      sum -= a.at(i);
    }
  }

  cout << sum << endl;
  return 0;
}
