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

#include <cstdio>

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
  vector<pair<int, int>> pi(n);
  rep(i, 0, n)
  {
    pi[i].second = i;
    // cin >> pi[i].first;
    scanf("%d", &pi[i].first);
  }

  sort(pi.begin(), pi.end());

  // rep(i, 0, n)
  // {
  //   cout << i << ": " << pi[i].first << ", " << pi[i].second << endl;
  // }

  int min_diff = INT32_MAX;
  rep(i, 0, n - k + 1)
  {
    int min_index = INT32_MAX;
    int max_index = 0;
    rep(j, 0, k)
    {
      int index = pi[i + j].second;

      if (min_index > index)
      {
        min_index = index;
      }
      if (max_index < index)
      {
        max_index = index;
      }
    }
    // cout << "max: " << max_index << ", min: " << min_index << endl;
    int diff = max_index - min_index;
    if (min_diff > diff)
    {
      min_diff = diff;
    }
  }

  cout << min_diff << endl;
  return 0;
}
