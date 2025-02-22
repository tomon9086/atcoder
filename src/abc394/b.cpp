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
  vector<pair<int, string>> ls(n);
  rep(i, 0, n)
  {
    string s;
    cin >> s;
    ls[i] = make_pair(s.size(), s);
  }

  sort(ls.begin(), ls.end());

  rep(i, 0, n)
  {
    cout << ls[i].second;
  }

  cout << endl;
  return 0;
}
