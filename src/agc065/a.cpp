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

ll mod(ll n, ll m)
{
  ll ret = n % m;
  return ret < 0 ? ret + m : ret;
}

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  ll sum = 0;
  rep(i, 1, n)
  {
    // cout << (a[i] - a[i - 1]) << " : " << mod((a[i] - a[i - 1]), k) << endl;
    sum += mod((a[i] - a[i - 1]), k);
  }

  cout << sum << endl;
  return 0;
}
