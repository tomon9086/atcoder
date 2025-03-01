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

  vector<vector<char>> v(n, vector<char>(n, '?'));

  rep(i, 0, n)
  {
    int j = n - i;
    char nuri = i % 2 == 0 ? '#' : '.';

    rep(x, i, j) rep(y, i, j)
    {
      v[x][y] = nuri;
    }
  }

  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      cout << v[i][j];
    }
    cout << endl;
  }

  return 0;
}
