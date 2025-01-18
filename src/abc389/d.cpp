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

double sq(double x)
{
  return x * x;
}

int main()
{
  int r;
  cin >> r;

  int count_45deg = 0;
  rep(i, 0, r)
  {
    if (2 * sq(i + 0.5) <= r * r)
    {
      count_45deg++;
    }
    else
    {
      break;
    }
  }

  cout << count_45deg << endl;
  return 0;
}
