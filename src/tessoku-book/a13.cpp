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

ll clamp(ll x, ll l, ll r)
{
  return min(max(x, l), r);
}

ll lbs(vector<int> &a, int k, int l, int r)
{
  if (l >= r)
    return clamp(a[l] <= k ? l : l - 1, 0, a.size() - 1);

  int mid = (l + r) / 2;
  if (a[mid] >= k)
    return lbs(a, k, l, mid);
  else
    return lbs(a, k, mid + 1, r);
}

ll ubs(vector<int> &a, int k, int l, int r)
{
  if (l >= r)
    return clamp(a[l] >= k ? l : l + 1, 0, a.size() - 1);

  int mid = (l + r) / 2;
  if (a[mid] >= k)
    return ubs(a, k, l, mid);
  else
    return ubs(a, k, mid + 1, r);
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0);
  rep(i, 0, n) cin >> a[i];

  ll count = 0;
  rep(i, 0, n)
  {
    // auto u = upper_bound(a.begin() + i + 1, a.end(), a[i] + k);
    // auto l = lower_bound(a.begin(), a.begin() + i, a[i] - k);
    // ll count_u = distance(a.begin() + i + 1, u);
    // ll count_l = distance(a.begin(), l);

    ll l = ubs(a, a[i] - k, 0, i);
    ll u = lbs(a, a[i] + k, i + 1, n);
    // cout << "l: " << l << ", u: " << u << endl;

    count += u - l;
  }

  cout << count / 2 << endl;
  return 0;
}
