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
  vector<vector<int>> v(n, vector<int>(0));

  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;

    a--;
    b--;

    v[a].push_back(b);
    v[b].push_back(a);
  }

  rep(i, 0, n)
  {
    cout << i + 1 << ": {";
    rep(j, 0, v[i].size())
    {
      if (j != 0)
        cout << ", ";

      cout << v[i][j] + 1;
    }
    cout << "}" << endl;
  }

  return 0;
}
