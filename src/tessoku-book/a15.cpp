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
  vector<int> a(n, 0);
  rep(i, 0, n) cin >> a[i];

  vector<int> table(n, 0);
  copy(a.begin(), a.end(), table.begin());
  sort(table.begin(), table.end());
  table.erase(unique(table.begin(), table.end()));

  // cout << table.size() << endl;
  // print_vec(int, table);

  rep(i, 0, n)
  {
    auto b = lower_bound(table.begin(), table.end(), a[i]);
    cout << distance(table.begin(), b) + 1 << " ";
  }

  cout << endl;
  return 0;
}
