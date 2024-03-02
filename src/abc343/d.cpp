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
  int n, t;
  cin >> n >> t;
  vector<ll> tokuten(n, 0);

  rep(i, t)
  {
    int a, b;
    cin >> a >> b;

    tokuten.at(--a) += b;

    vector<ll> t(n);
    partial_sort_copy(tokuten.begin(), tokuten.end(), t.begin(), t.end());
    reverse(t.begin(), t.end());
    // print_vec(int, t);

    int count = 1;
    ll prev = t.at(0);
    for (int j = 1; j < n; j++)
    {
      if (t.at(j) != prev)
      {
        count++;
        prev = t.at(j);
      }
      else if (prev == 0)
      {
        break;
      }
    }

    cout << count << endl;
  }

  return 0;
}
