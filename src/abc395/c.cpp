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

int MAX = 1000000;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }

  // print_vec(int, a);

  int shortest_length = MAX;
  rep(i, 1, n)
  {
    int nearest_index = -1;
    for (int j = i - 1; j >= 0; j--)
    {
      if (a[j] == a[i])
      {
        nearest_index = j;
        break;
      }
    }

    if (nearest_index >= 0)
    {
      int index = i - nearest_index + 1;
      // cout << a[i] << " found: " << index << endl;
      if (index < shortest_length)
      {
        shortest_length = index;
      }
    }
  }

  if (shortest_length == MAX)
  {
    cout << -1 << endl;
    return 0;
  }

  cout << shortest_length << endl;
  return 0;
}
