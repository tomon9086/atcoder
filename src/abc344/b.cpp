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
  vector<int> a;
  int v = -1;
  while (v != 0)
  {
    cin >> v;
    a.push_back(v);
  }

  // print_vec(int, a);

  reverse(a.begin(), a.end());

  rep(i, a.size()) cout << a.at(i) << endl;

  return 0;
}
