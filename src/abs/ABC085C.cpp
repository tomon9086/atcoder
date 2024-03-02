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
  int n, y;
  cin >> n >> y;

  rep(i, n + 1) rep(j, n - i + 1) rep(k, n - i - j + 1)
  {
    if (i + j + k != n)
    {
      continue;
    }

    if (i * 10000 + j * 5000 + k * 1000 == y)
    {
      cout << i << " " << j << " " << k << endl;

      return 0;
    }
  }

  cout << -1 << " " << -1 << " " << -1 << endl;

  return 0;
}
