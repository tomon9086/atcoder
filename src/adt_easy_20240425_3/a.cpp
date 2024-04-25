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
  int n, s, k;
  cin >> n >> s >> k;

  int sum = 0;
  rep(i, 0, n)
  {
    int p, q;
    cin >> p >> q;
    sum += p * q;
  }
  if (sum < s)
  {
    sum += k;
  }

  cout << sum << endl;
  return 0;
}