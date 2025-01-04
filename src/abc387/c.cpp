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

ll llpow(int base, int exp)
{
  ll res = 1;
  rep(i, 0, exp)
  {
    res *= base;
  }
  return res;
}

ll hebi_max(int digits, int initial)
{
  ll res = 0;
  rep(i, 0, digits - 1)
  {
    res += (initial - 1) * llpow(10, i);
  }
  res += initial * llpow(10, digits - 1);

  return res;
}

ll count_hebi(int digits, int initial)
{
  if (digits < 2)
  {
    return 0;
  }
  else if (initial <= 0)
  {
    return llpow(initial, digits - 1) + count_hebi(digits - 1, 9);
  }
  else
  {
    return llpow(initial, digits - 1) + count_hebi(digits, initial - 1);
  }
}

ll count_not_hebi_from_max_to_hebi_max(int initial, ll hebi_max, ll max)
{
  if (hebi_max < max)
  {
    return 0;
  }

  string max_str = to_string(max);
  int radix = initial - 1;

  ll count = 0;
  rep(i, 1, max_str.size() - 1)
  {
    count += (max_str[i] - '0') * llpow(radix, max_str.size() - i - 1);

    // cout << "radix: " << radix << ", i: " << i << ", llpow: " << llpow(radix, max_str.size() - i - 1) << endl;
  }

  return count;
}

int main()
{
  ll l, r;
  cin >> l >> r;

  string l_str = to_string(l);
  int l_digits = l_str.size();
  int l_initial = l_str[0] - '0';
  string r_str = to_string(r);
  int r_digits = r_str.size();
  int r_initial = r_str[0] - '0';

  ll r_hebi = count_hebi(r_digits, r_initial);
  ll r_hebi_max = hebi_max(r_digits, r_initial);
  ll r_hebi_diff = r_hebi_max - r;
  ll r_not_hebi_from_max_to_hebi_max = count_not_hebi_from_max_to_hebi_max(r_initial, r_hebi_max, r);
  if (r_hebi_diff > 0)
  {
    r_hebi += r_not_hebi_from_max_to_hebi_max;
    // r_hebi += -r_hebi_diff + r_not_hebi_from_max_to_hebi_max;
  }

  ll l_hebi = count_hebi(l_digits, l_initial);
  ll l_hebi_max = hebi_max(l_digits, l_initial);
  ll l_hebi_diff = l_hebi_max - l;
  ll l_not_hebi_from_max_to_hebi_max = count_not_hebi_from_max_to_hebi_max(l_initial, l_hebi_max, l);
  if (l_hebi_diff > 0)
  {
    l_hebi += l_not_hebi_from_max_to_hebi_max;
    // l_hebi += -l_hebi_diff + l_not_hebi_from_max_to_hebi_max;
  }

  // cout << "r           : " << r << endl;
  // cout << "hebi_max    : " << hebi_max(r_digits, r_initial) << endl;
  // cout << "count_hebi  : " << count_hebi(r_digits, r_initial) << endl;
  // cout << "r_hebi_diff : " << r_hebi_diff << endl;
  // cout << "r_nhnhm     : " << r_not_hebi_from_max_to_hebi_max << endl;
  // cout << "r_hebi      : " << r_hebi << endl;

  // cout << "l           : " << l << endl;
  // cout << "hebi_max    : " << hebi_max(l_digits, l_initial) << endl;
  // cout << "count_hebi  : " << count_hebi(l_digits, l_initial) << endl;
  // cout << "l_hebi_diff : " << l_hebi_diff << endl;
  // cout << "l_nhnhm     : " << l_not_hebi_from_max_to_hebi_max << endl;
  // cout << "l_hebi      : " << l_hebi << endl;

  cout << r_hebi - l_hebi << endl;
  return 0;
}
