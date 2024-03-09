#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <utility>
#include <vector>
#include <numeric>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define print_pair(pair) cout << "{}" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  int n, l, k;
  cin >> n >> l >> k;
  vector<int> a(n + 1);
  int prev = 0;
  rep(i, n)
  {
    int ai;
    cin >> ai;
    a.at(i) = ai - prev;
    prev = ai;
  }
  a.at(n) = l - prev;

  int mokuhyo = l / (k + 1);
  int max_below_mokuhyo = 0;
  int start_i = 0;

  rep(i, n + 1)
  {
    int sum = accumulate(a.begin() + start_i, a.begin() + i + 1, 0);
    if (sum >= mokuhyo)
    {
      start_i = i;
      continue;
    }

    if (max_below_mokuhyo < sum)
    {
      // cout << sum << " " << start_i + 1 << " ~ " << i + 1 << endl;
      max_below_mokuhyo = sum;
    }
  }

  cout << max_below_mokuhyo << endl;

  return 0;
}
