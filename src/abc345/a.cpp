#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, begin, end) for (ll i = (begin); i < (end); i++)
#define print_pair(pair) cout << "{}" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  string s;
  cin >> s;

  if (s.at(0) == '<' && s.at(s.size() - 1) == '>')
  {
    rep(i, 1, s.size() - 1)
    {
      if (s.at(i) != '=')
      {
        cout << "No" << endl;
        return 0;
      }
    }

    cout << "Yes" << endl;
    return 0;
  }
  else
  {
    cout << "No" << endl;
    return 0;
  }

  return 0;
}
