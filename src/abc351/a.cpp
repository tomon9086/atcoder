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
  int sum_a = 0;
  int sum_b = 0;
  rep(i, 0, 9)
  {
    int p;
    cin >> p;
    sum_a += p;
  }
  rep(i, 0, 8)
  {
    int p;
    cin >> p;
    sum_b += p;
  }

  int diff = sum_a - sum_b;
  if (diff < 0)
  {
    diff = 0;
  }

  cout << diff + 1 << endl;
  return 0;
}
