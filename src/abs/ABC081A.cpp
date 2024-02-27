#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
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
  string s;
  cin >> s;

  int count = 0;
  rep(i, s.size()) if (s[i] == '1') count++;
  cout << count << endl;

  return 0;
}
