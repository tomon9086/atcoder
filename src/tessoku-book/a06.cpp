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
  int n, q;
  cin >> n >> q;
  vector<int> sum(n);
  rep(i, 0, n)
  {
    if (i > 0)
    {
      sum[i] = sum[i - 1];
    }

    int a;
    cin >> a;
    sum[i] += a;
  }

  // print_vec(int, sum);

  rep(i, 0, q)
  {
    int l, r;
    cin >> l >> r;
    int l_sum = l == 1 ? 0 : sum[l - 2];
    int r_sum = sum[r - 1];

    cout << r_sum - l_sum << endl;
  }

  return 0;
}
