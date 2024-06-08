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
  string s;
  cin >> s;

  int lower_count = 0;
  int upper_count = 0;
  string lower_s, upper_s;
  rep(i, 0, s.size())
  {
    if ('a' <= s[i] && s[i] <= 'z')
    {
      lower_s += s[i];
      upper_s += s[i] + 'A' - 'a';
      lower_count++;
    }
    else
    {
      lower_s += s[i] + 'a' - 'A';
      upper_s += s[i];
      upper_count++;
    }
  }

  if (lower_count < upper_count)
  {
    cout << upper_s << endl;
  }
  else
  {
    cout << lower_s << endl;
  }
  return 0;
}
