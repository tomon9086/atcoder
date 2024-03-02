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

vector<string> phrases = {
    "eraser",
    "erase",
    "dreamer",
    "dream",
};

int main()
{
  string s;
  cin >> s;

  while (s.size())
  {
    bool found = false;
    rep(i, phrases.size())
    {
      int pos = s.find(phrases.at(i));
      // cout << s << " " << phrases.at(i) << " " << pos << endl;
      if (pos != string::npos)
      {
        s = s.replace(pos, phrases.at(i).size(), "");
        found = true;
        break;
      }
    }

    if (!found)
    {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  return 0;
}
