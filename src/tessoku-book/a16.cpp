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
  vector<int> a(n - 1), b(n - 2);
  rep(i, 0, n - 1) cin >> a[i];
  rep(i, 0, n - 2) cin >> b[i];

  int sum = 0;
  rep(i, 0, n)
  {
    if (i >= n - 1)
      break;

    int w_1 = INT_MAX, w_2 = INT_MAX;

    if (i < a.size())
      w_1 = a[i];
    if (i + 1 < a.size())
      w_1 += a[i + 1];
    if (i < b.size())
      w_2 = b[i];

    cout << i << " " << w_1 << " " << w_2 << endl;

    if (w_1 < w_2)
    {
      sum += w_1;
    }
    else
    {
      sum += w_2;
      i++;
    }
  }

  cout << sum << endl;
  return 0;
}
