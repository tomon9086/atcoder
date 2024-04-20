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
  // vector<int> a(n);
  // (A_i, i)
  vector<pair<int, int>> a(n);
  rep(i, 0, n)
  {
    cin >> a[i].first;
    a[i].second = i;
  }
  // rep(i, 0, n) print_pair(a[i]);
  sort(a.begin(), a.end());
  // rep(i, 0, n) print_pair(a[i]);

  vector<pair<int, int>> ret;

  rep(i, 0, n)
  {
    if (i != a[i].second)
    {
      // rep(i, 0, n) print_pair(a[i]);
      // cout << "swap: " << i << " " << a[i].second << endl;
      // puts("=======");

      if (i < a[i].second)
      {

        ret.push_back({i, a[i].second});
      }
      else
      {
        ret.push_back({a[i].second, i});
      }
      int hoge = a[i].second;
      swap(a[i].second, a[a[i].second].second);
      // cout << a[i].second << " " << a[hoge].second << endl;
      // a[i].second = i;
      // a[hoge].second = hoge;
      // cout << a[i].second << " " << a[hoge].second << endl;

      // rep(i, 0, n) print_pair(a[i]);
      // puts("=======");
    }
  }

  int k = ret.size();
  cout << k << endl;
  rep(i, 0, k) cout << ret[i].first + 1 << " " << ret[i].second + 1 << endl;

  return 0;
}
