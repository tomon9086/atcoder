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

  int seq_w_n = 0;
  rep(i, 0, s.size())
  {
    if (s[i] == 'W')
    {
      seq_w_n++;
    }

    else if (seq_w_n > 0 && s[i] == 'A')
    {
      rep(j, 0, seq_w_n + 1)
      {
        if (j == 0)
          cout << 'A';
        else
          cout << 'C';
      }

      seq_w_n = 0;
    }

    else
    {
      if (seq_w_n > 0)
      {
        rep(j, 0, seq_w_n)
        {
          cout << 'W';
        }

        seq_w_n = 0;
      }

      cout << s[i];
    }
  }

  if (seq_w_n > 0)
  {
    rep(j, 0, seq_w_n)
    {
      cout << 'W';
    }
  }

  cout << endl;
  return 0;
}
