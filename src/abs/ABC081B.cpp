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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  int count = 0;
  while (true)
  {
    rep(i, n)
    {
      if (a.at(i) % 2 != 0)
      {
        cout << count << endl;
        return 0;
      }

      a.at(i) /= 2;
    }

    count++;
  }

  return 0;
}
