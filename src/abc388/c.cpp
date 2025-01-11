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

int main()
{
  int n;
  cin >> n;
  vector<int> a(n, 0);
  rep(i, 0, n) cin >> a[i];

  ll count = 0;
  rep(i, 0, n - 1)
  {
    auto b = lower_bound(a.begin() + i + 1, a.end(), a[i] * 2);
    int j = distance(a.begin(), b);
    // cout << "j: " << j << endl;
    if (j < a.size())
      count += n - j;
  }

  cout << count << endl;
  return 0;
}
