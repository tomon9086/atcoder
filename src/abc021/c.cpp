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
  int n, m, a, b;
  cin >> n >> a >> b >> m;
  vector<vector<int>> edge(m);
  rep(i, 0, m)
  {
    int x, y;
    cin >> x >> y;
    edge.at(x).push_back(y);
    edge.at(y).push_back(x);
  }

  rep(i, 0, m)
  {
    cout << i << ": " << endl;
    print_vec(int, edge.at(i));
  }

  cout << 1000000007 << endl;
  return 0;
}
