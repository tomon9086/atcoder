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

  string bin = "0000000000";
  rep(i, 0, bin.size())
  {
    int dig = bin.size() - i - 1;
    int regix = pow(2, dig);
    bin[i] = (n / regix) + '0';
    n %= regix;
  }

  cout << bin << endl;
  return 0;
}
