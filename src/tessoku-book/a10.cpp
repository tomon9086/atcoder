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
#define print_pair(pair) cout << "{" << pair.first << ", " << pair.second << "}"
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  int n, d;
  cin >> n;
  vector<pair<int, size_t>> a_i(n);
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    a_i[i] = make_pair(a, i);
  }
  cin >> d;

  // rep(i, 0, n) print_pair(a_i[i]);
  // cout << endl;
  sort(a_i.begin(), a_i.end());
  reverse(a_i.begin(), a_i.end());
  // rep(i, 0, n) print_pair(a_i[i]);
  // cout << endl;

  rep(i, 0, d)
  {
    int l, r;
    cin >> l >> r;

    rep(j, 0, n)
    {
      if (a_i[j].second < l - 1 || r - 1 < a_i[j].second)
      {
        cout << a_i[j].first << endl;
        break;
      }
    }
  }

  return 0;
}
