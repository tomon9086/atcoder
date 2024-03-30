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

ll distance(ll hou, set<ll> d_mod)
{
  auto minmax = minmax_element(d_mod.begin(), d_mod.end());
  ll d_min = *minmax.first;
  ll d_max = *minmax.second;

  ll zero_hasamanai = d_max - d_min + 1;
  ll zero_hasamu = (d_min + 1) + (hou - d_max + 1);

  cout << "zero_hasamanai: " << zero_hasamanai << endl;
  cout << "   zero_hasamu: " << zero_hasamu << endl;

  if (zero_hasamanai - zero_hasamu > 0)
  {
    set<ll> st;
    // copy(d_mod.begin(), d_mod.end(), back_inserter(v));
    // rep(i, 0, v.size()) v[i] = (hou + v[i] - d_min - 1) % hou;
    for (auto it = d_mod.begin(); it != d_mod.end(); it++)
    {
      ll hgoe = (*it - d_min - 1) % hou;
      if (hgoe < 0)
      {
        st.insert(hou + hgoe);
      }
      else
      {
        st.insert(hgoe);
      }
    }
    auto minmax = minmax_element(st.begin(), st.end());
    ll d_min = *minmax.first;
    ll d_max = *minmax.second;

    print_vec(ll, st);

    ll zero_hasamanai = d_max - d_min + 1;
    cout << "zero_hasamanai: " << zero_hasamanai << endl;

    return zero_hasamanai;
  }
  else
  {
    return zero_hasamanai;
  }
}

int main()
{
  ll n, a, b;
  cin >> n >> a >> b;
  set<ll> d_mod;
  rep(i, 0, n)
  {
    ll d;
    cin >> d;
    d_mod.insert(d % (a + b));
  }

  print_vec(ll, d_mod);
  ll dist = distance(a + b, d_mod);
  if (dist > a)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }

  return 0;
}
