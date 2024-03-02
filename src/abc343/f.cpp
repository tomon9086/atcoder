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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  rep(i, q)
  {
    int type;
    cin >> type;

    if (type == 1)
    {
      int p, x;
      cin >> p >> x;

      a.at(p - 1) = x;
    }
    else if (type == 2)
    {
      int l, r;
      cin >> l >> r;

      vector<int> aa(r - l + 1);
      partial_sort_copy(a.begin() + l - 1, a.begin() + r, aa.begin(), aa.end());
      reverse(aa.begin(), aa.end());
      // print_vec(int, aa);

      int count = 0;
      int t1 = aa.at(0);
      int t2 = -1;
      rep(j, aa.size())
      {
        if (t2 < 0 && t1 != aa.at(j))
        {
          t2 = aa.at(j);
          count++;
        }
        else if (t2 == aa.at(j))
        {
          count++;
        }
        else if (t2 >= 0 && t1 != aa.at(j) && t2 != aa.at(j))
        {
          break;
        }
      }

      cout << count << endl;
    }
  }

  return 0;
}
