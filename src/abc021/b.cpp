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
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  vector<int> p(k + 2);
  p.at(0) = a;
  rep(i, 1, k + 1) cin >> p.at(i);
  p.at(k + 1) = b;

  sort(p.begin(), p.end());

  int prev = -1;
  rep(i, 0, k + 2)
  {
    if (p.at(i) == prev)
    {
      cout << "NO" << endl;
      return 0;
    }

    prev = p.at(i);
  }

  cout << "YES" << endl;
  return 0;
}
