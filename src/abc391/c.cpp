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
  int n, q;
  cin >> n >> q;

  vector<int> pegeon_pos(n);
  rep(i, 0, n) pegeon_pos[i] = i;

  vector<int> pegeons_in_nest(n, 1);

  int count = 0;

  rep(i, 0, q)
  {
    int type;
    cin >> type;

    switch (type)
    {
    case 1:
    {
      int a, b;
      cin >> a >> b;
      int prev_pegeons_in_nest;

      prev_pegeons_in_nest = pegeons_in_nest[pegeon_pos[a - 1]];
      pegeons_in_nest[pegeon_pos[a - 1]]--;
      if (prev_pegeons_in_nest >= 2 && pegeons_in_nest[pegeon_pos[a - 1]] < 2)
        count--;
      prev_pegeons_in_nest = pegeons_in_nest[b - 1];
      pegeons_in_nest[b - 1]++;
      if (prev_pegeons_in_nest < 2 && pegeons_in_nest[b - 1] >= 2)
        count++;

      pegeon_pos[a - 1] = b - 1;
      break;
    }

    case 2:
    {
      // print_vec(int, pegeons_in_nest);

      cout << count << endl;
      break;
    }
    }
  }

  return 0;
}
