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

vector<ll> memo(100, -1);
ll factorial(ll n)
{
  if (n == 0)
    return 1;
  if (memo[n] != -1)
    return memo[n];

  return memo[n] = n * factorial(n - 1);
}

int main()
{
  ll x;
  cin >> x;

  rep(i, 1, 100)
  {
    if (factorial(i) == x)
    {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
