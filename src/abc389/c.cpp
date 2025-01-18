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
  int q;
  cin >> q;

  vector<int> snake_lengths(0);
  rep(_, 0, q)
  {
    int type;
    cin >> type;
    switch (type)
    {
    case 1:
      int l;
      cin >> l;

      snake_lengths.push_back(l);
      break;
    case 2:
      snake_lengths.erase(snake_lengths.begin());
      break;
    case 3:
      int k;
      cin >> k;

      ll sum = 0;
      rep(i, 0, k - 1)
      {
        sum += snake_lengths[i];
      }

      cout << sum << endl;
      break;
    }

    // print_vec(int, snake_lengths);
  }

  return 0;
}
