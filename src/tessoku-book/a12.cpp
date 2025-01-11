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

ll check(vector<int> &a, int sec)
{
  ll papers = 0;
  rep(i, 0, a.size()) papers += sec / a[i];

  return papers;
}

int search(vector<int> &a, int k, int l, int r)
{
  int size = r - l;
  if (size <= 1)
    return l;

  int mid = l + size / 2;
  ll papers = check(a, mid);
  if (papers >= k)
    return search(a, k, l, mid);
  else
    return search(a, k, mid + 1, r);
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0);
  rep(i, 0, n) cin >> a[i];

  cout << search(a, k, 0, 1e9) << endl;
  return 0;
}
