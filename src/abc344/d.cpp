#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define print_pair(pair) cout << "{}" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  string t;
  cin >> t;
  int n;
  cin >> n;
  vector<vector<string>> s(n);

  rep(i, n)
  {
    int a;
    cin >> a;
    s.at(i) = vector<string>(a);
    rep(j, a) cin >> s.at(i).at(j);
  }

  int count = -1;
  rep(i, n) rep(j, s.at(i).size())
  {
    int curr = 0;
    if ((count < -1 && curr > 0) || count > curr)
    {
      count = curr;
    }
  }

  cout << "Hello, world!" << endl;
  return 0;
}
