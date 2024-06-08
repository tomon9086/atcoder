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

  vector<vector<int>> a(n);
  rep(i, 0, n)
  {
    int hoge;
    cin >> hoge;
    hoge--;

    a[i].push_back(i);
    if (hoge != i)
    {
      a[i].push_back(hoge);
    }
  }

  rep(i, 0, n)
  {
    print_vec(int, a[i]);
  }

  int count = 0;
  rep(i, 0, n)
  {
    count += a[i].size();
  }

  cout << count << endl;
  return 0;
}
