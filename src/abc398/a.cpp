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

  if (n % 2 == 0)
  {
    rep(i, 0, n / 2 - 1)
    {
      cout << "-";
    }
    cout << "=";
    cout << "=";
    rep(i, 0, n / 2 - 1)
    {
      cout << "-";
    }
  }
  else
  {
    rep(i, 0, n / 2)
    {
      cout << "-";
    }
    cout << "=";
    rep(i, 0, n / 2)
    {
      cout << "-";
    }
  }

  cout << endl;
  return 0;
}
