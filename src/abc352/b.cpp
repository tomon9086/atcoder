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
  string s, t;
  cin >> s >> t;

  int cursor_s = 0;
  int cursor_t = 0;
  while (true)
  {
    if (s.size() <= cursor_s)
    {
      cout << endl;
      return 0;
    }

    if (s[cursor_s] == t[cursor_t])
    {
      cout << cursor_t + 1 << " ";

      cursor_s++;
      cursor_t++;
    }
    else
    {
      cursor_t++;
    }
  }

  return 0;
}
