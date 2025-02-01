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
  int n, m;
  cin >> n >> m;

  vector<vector<char>> s(n, vector<char>(n));
  rep(i, 0, n)
  {
    string line;
    cin >> line;

    rep(j, 0, n) s[i][j] = line[j];
  }

  vector<vector<char>> t(m, vector<char>(n));
  rep(i, 0, m)
  {
    string line;
    cin >> line;

    rep(j, 0, m) t[i][j] = line[j];
  }

  rep(a, 0, n - m + 1) rep(b, 0, n - m + 1)
  {
    bool ok = true;
    rep(i, 0, m) rep(j, 0, m)
    {
      if (s[a + i][b + j] != t[i][j])
        ok = false;
    }

    if (ok)
      cout << a + 1 << " " << b + 1 << endl;
  }

  return 0;
}
