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

vector<ll> kaibun_rippou = {
    1,
    8,
    343,
    1331,
    1030301,
    1367631,
    1003003001,
    10662526601,
    1000300030001,
    1030607060301,
    1334996994331,
    1000030000300001,
    1033394994933301,
    1331399339931331,
};

int main()
{
  reverse(kaibun_rippou.begin(), kaibun_rippou.end());

  ll n;
  cin >> n;

  rep(i, kaibun_rippou.size())
  {
    if (kaibun_rippou.at(i) <= n)
    {
      cout << kaibun_rippou.at(i) << endl;
      return 0;
    }
  }

  // rep(i, 1000000)
  // {
  //   ll sq3 = i * i * i;
  //   string sq3_str = to_string(sq3);
  //   string sq3_str_f = sq3_str.substr(0, sq3_str.size() / 2);
  //   string sq3_str_b = sq3_str.substr(ceil((double)sq3_str.size() / 2));
  //   reverse(sq3_str_b.begin(), sq3_str_b.end());

  //   if (sq3_str_f == sq3_str_b)
  //   {
  //     cout << sq3 << endl;
  //   }
  // }

  return 0;
}
