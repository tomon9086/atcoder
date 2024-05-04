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

bool compare_by_b(pair<int, int> a, pair<int, int> b)
{
  if (a.second != b.second)
  {
    return a.second < b.second;
  }
  else
  {
    return a.first < b.first;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> ab(n);
  rep(i, 0, n) cin >> ab[i].first >> ab[i].second;

  sort(ab.begin(), ab.end());
  ll sum_shoulder = 0;
  rep(i, 1, n)
  {
    // cout << i << ": " << ab[i].first << endl;
    sum_shoulder += ab[i].first;
  }
  sum_shoulder += ab.front().second;

  sort(ab.begin(), ab.end(), compare_by_b);
  ll sum_head = 0;
  rep(i, 1, n)
  {
    // cout << i << ": " << ab[i].first << endl;
    sum_head += ab[i].first;
  }
  sum_head += ab.front().second;

  if (sum_shoulder < sum_head)
  {
    cout << sum_head << endl;
  }
  else
  {
    cout << sum_shoulder << endl;
  }
  return 0;
}
