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

  vector<pair<int, char>> alph_freq(26);
  rep(i, 0, 26) alph_freq[i].second = i + 'a';
  rep(i, 0, s.size()) alph_freq[s[i] - 'a'].first++;

  sort(alph_freq.begin(), alph_freq.end());
  reverse(alph_freq.begin(), alph_freq.end());

  char mode_ch = alph_freq[0].second;

  int count = 0;
  while (true)
  {
    count++;

    string t_prime = "";

    rep(i, 0, s.size())
    {
      if (s[i] == mode_ch || s[i + 1] == mode_ch)
      {
        t_prime += mode_ch;
      }
      else
      {
        t_prime += s[i];
      }
    }

    int not_mode_ch_index = -1;
    rep(i, 0, t_prime.size())
    {
      if (t_prime[i] != mode_ch)
      {
        not_mode_ch_index = i;
        break;
      }
    }
    if (not_mode_ch_index == -1)
    {
      break;
    }

    s = t_prime.substr(0, not_mode_ch_index) + t_prime.substr(not_mode_ch_index + 1, t_prime.size());

    // cout << count << ": " << s << endl;
  }

  cout << count - 1 << endl;
  return 0;
}
