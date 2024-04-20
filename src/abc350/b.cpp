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
#define print_pair(pair) cout << "{}" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;
  vector<bool> d(n, true);

  rep(i, 0, q)
  {
    int ha;
    cin >> ha;

    d[ha - 1] = !d[ha - 1];

    // print_vec(int, d);
  }

  int count = 0;
  rep(i, 0, n)
  {
    if (d[i])
    {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}
