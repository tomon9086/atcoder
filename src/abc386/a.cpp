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
  map<int, int> map;
  for (int i = 1; i <= 13; i++)
  {
    map[i] = 0;
  }

  for (int i = 0; i < 4; i++)
  {
    int v;
    cin >> v;
    map[v]++;
  }

  int not_zero_count = 0;
  for (int i = 1; i <= 13; i++)
  {
    if (map[i] > 0)
    {
      not_zero_count++;
    }
  }

  if (not_zero_count == 2)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
