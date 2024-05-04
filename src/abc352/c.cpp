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
  vector<pair<int, pair<int, int>>> ab(n);
  rep(i, 0, n)
  {
    int a, b;
    cin >> a >> b;
    // diff
    ab[i].first = a - b;
    // shoulder
    ab[i].second.first = a;
    // head
    ab[i].second.second = b;
  }

  sort(ab.begin(), ab.end());
  ll sum = 0;
  rep(i, 1, n)
  {
    // cout << i << ": " << ab[i].first << endl;
    sum += ab[i].second.first;
  }
  sum += ab.front().second.second;

  cout << sum << endl;
  return 0;
}
