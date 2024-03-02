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
#define print_vec(type, v)                                     \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, " ")); \
  cout << endl;

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  vector<vector<int>> am(n);
  // rep(i, n) rep(j, n) am.at(i).at(j) = -1;
  rep(i, n)
  {
    rep(j, n)
    {
      bool is_rinsetsu;
      cin >> is_rinsetsu;
      // cin >> a.at(i).at(j);

      if (is_rinsetsu)
      {
        am.at(i).push_back(j + 1);
      }
    }

    sort(am.at(i).begin(), am.at(i).end());

    print_vec(int, am.at(i));
  }

  return 0;
}
