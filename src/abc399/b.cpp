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
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, 0, n) cin >> p[i];

  vector<int> pos(n);
  vector<pair<int, int>> p_i(n);
  rep(i, 0, n)
  {
    p_i[i] = {p[i], i};
  }
  sort(p_i.begin(), p_i.end());
  reverse(p_i.begin(), p_i.end());

  int prev_p = -1;
  int r = 0;
  int count = 0;
  rep(i, 0, n)
  {
    int curr_p = p_i[i].first;
    if (curr_p != prev_p)
    {
      r += count + 1;
      count = 0;
    }
    else
    {
      count++;
    }

    pos[p_i[i].second] = r;
    prev_p = curr_p;
  }

  rep(i, 0, n)
  {
    cout << pos[i] << endl;
  }
  return 0;
}
