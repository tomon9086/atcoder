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
  int n, q;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  cin >> q;
  rep(i, q)
  {
    int type;
    cin >> type;

    if (type == 1)
    {
      int x, y;
      cin >> x >> y;

      auto iter = find(a.begin(), a.end(), x);
      a.insert(iter + 1, y);
    }
    else
    {
      int x;
      cin >> x;

      auto iter = find(a.begin(), a.end(), x);
      a.erase(iter);
    }
  }

  print_vec(int, a);

  return 0;
}
