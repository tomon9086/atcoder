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
  int n, k;
  cin >> n >> k;

  int count = 0;
  rep(i, 1, n + 1) rep(j, 1, n + 1)
  {
    int s = k - i - j;
    if (1 <= s && s <= n)
    {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}
