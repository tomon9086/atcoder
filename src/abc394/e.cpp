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
  int n;
  cin >> n;

  vector<pair<pair<int, int>, char>> map(0);
  rep(i, 0, n) rep(j, 0, n)
  {
    char label;
    cin >> label;

    if (label != '-')
      map.push_back(make_pair(make_pair(i, j), label));
  }

  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      cout << (char)(i + j + 'a');
    }

    cout << endl;
  }

  return 0;
}
