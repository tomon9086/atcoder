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
  int d, n;
  cin >> d >> n;

  vector<int> attendee_count(d, 0);
  rep(i, 0, n)
  {
    int l, r;
    cin >> l >> r;

    rep(j, l - 1, r) attendee_count[j]++;
  }

  rep(i, 0, d) cout << attendee_count[i] << endl;

  return 0;
}
