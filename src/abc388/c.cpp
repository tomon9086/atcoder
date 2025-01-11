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

  int count = 0;
  rep(i, 0, n - 1) rep(j, i + 1, n)
  {
    if (a[j] >= a[i] * 2)
    {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}
