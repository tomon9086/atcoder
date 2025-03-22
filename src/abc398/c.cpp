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

#define rep(i, begin, end) for (int i = (begin); i < (end); i++)
#define print_pair(pair) cout << "{" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  int n;
  cin >> n;
  // vector<pair<int, int>> a(n);
  vector<int> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }

  vector<int> b(n);
  copy(a.begin(), a.end(), b.begin());

  sort(b.begin(), b.end());

  // print_vec(int, b);

  int max = -1;
  int curr = 0;
  while (true)
  {
    auto it = upper_bound(b.begin(), b.end(), b[curr]);
    // cout << "curr: " << curr << " i: " << it - b.begin() << endl;
    if (it == b.end())
      break;

    if ((it - b.begin()) - curr > 1)
    {
      curr = it - b.begin();
    }
    else
    {
      max = b[curr];
      curr++;
    }
  }

  if (max == -1)
  {
    cout << -1 << endl;
    return 0;
  }

  rep(i, 0, n)
  {
    if (a[i] == max)
    {
      cout << i + 1 << endl;
      break;
    }
  }

  return 0;
}
