#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, begin, end) for (ll i = (begin); i < (end); i++)
#define rep_dec(i, begin, end) for (ll i = (begin); i >= (end); i--)
#define print_pair(pair) cout << "{}" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  int n, a, b, c;
  cin >> n;
  cin >> a >> b >> c;

  // vector<int> abc(3);
  // rep(i, 0, 3) cin >> abc[i];
  // sort(abc.begin(), abc.end());
  // reverse(abc.begin(), abc.end());
  // a = abc[0];
  // b = abc[1];
  // c = abc[2];

  rep(i, 0, 10000)
  {
    // cout << "i: " << i << endl;
    rep(j, 0, i) rep(k, 0, i - j)
    {
      int l = i - j - k;
      // cout << "j: " << j << ", k: " << k << ", l: " << l << endl;
      int amount_a = a * j + b * k + c * l;
      int amount_b = b * j + c * k + a * l;
      int amount_c = c * j + a * k + b * l;

      if (amount_a == n || amount_b == n || amount_c == n)
      {
        cout << i << endl;
        return 0;
      }
    }
  }

  return 0;
}
