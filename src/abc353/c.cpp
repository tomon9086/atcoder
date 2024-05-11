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

const int HOU = 100000000;

ll paa(int n, vector<int> a, int i)
{
  // return 0.5 * (n - i - 1) * (a[0] + a[i + 1] + a.back());

  ll sum = 0;
  rep(k, i + 1, n)
  {
    sum += (a[i] + a[k]) % HOU;
    // cout << "a: " << i << " " << k << " = " << sum << endl;
  }

  return sum;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  ll sum = 0;
  rep(i, 0, n - 1)
  {
    // sum += (i + 1) * paa(n, a, i);
    sum += paa(n, a, i);
    // cout << "b: " << i + 1 << " = " << sum << endl;
  }

  cout << sum << endl;
  return 0;
}
