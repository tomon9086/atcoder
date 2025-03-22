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
  vector<int> a(7);
  rep(i, 0, 7)
  {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  vector<int> separator(13);

  rep(i, 0, separator.size())
  {
    auto it = upper_bound(a.begin(), a.end(), i + 1);
    separator[i] = it - a.begin();
  }

  // print_vec(int, a);
  // print_vec(int, separator);

  bool dist_2 = false;
  bool dist_3 = false;

  int prev = 0;
  rep(i, 1, separator.size())
  {
    if (separator[i] - prev >= 3)
    {
      dist_3 = true;
      prev = separator[i];
      continue;
    }
    if (separator[i] - prev >= 2)
    {
      dist_2 = true;
      prev = separator[i];
      continue;
    }

    prev = separator[i];
  }

  if (dist_2 && dist_3)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
