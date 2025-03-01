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

  int prev = 0;
  rep(i, 0, n)
  {
    int a;
    cin >> a;

    if (a <= prev)
    {
      cout << "No" << endl;
      return 0;
    }

    prev = a;
  }

  cout << "Yes" << endl;
  return 0;
}
