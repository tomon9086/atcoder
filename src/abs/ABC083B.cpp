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
  int n, a, b;
  cin >> n >> a >> b;

  int sum = 0;
  for (int i = 0; i <= n; i++)
  {
    int tmp = i;
    int d_sum = 0;
    while (tmp > 0)
    {
      d_sum += tmp % 10;
      tmp /= 10;
    }
    if (a <= d_sum && d_sum <= b)
    {
      sum += i;
    }
  }

  cout << sum << endl;
  return 0;
}
