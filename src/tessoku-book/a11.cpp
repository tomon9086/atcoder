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

size_t binary_search(vector<int> &a, int x, size_t offset = 0)
{
  if (a.size() == 1)
    return a[0] == x ? offset : -1;

  size_t half_i = a.size() / 2;
  if (x < a[half_i])
  {
    vector<int> half(a.begin(), a.begin() + half_i);
    return binary_search(half, x, offset);
  }
  else
  {
    vector<int> half(a.begin() + half_i, a.end());
    return binary_search(half, x, offset + half_i);
  }
}

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  cout << binary_search(a, x) + 1 << endl;
  return 0;
}
