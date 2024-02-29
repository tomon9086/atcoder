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

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  int alice = 0, bob = 0;
  rep(i, n)
  {
    if (i % 2 == 0)
    {
      alice += a.at(i);
    }
    else
    {
      bob += a.at(i);
    }
  }

  cout << alice - bob << endl;

  return 0;
}
