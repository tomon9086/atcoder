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

  vector<int> pigeon_nest(n);
  rep(i, 0, n)
  {
    pigeon_nest[i] = i;
  }

  vector<vector<int>> nest_pigeons(n, vector<int>(0));
  rep(i, 0, n)
  {
    nest_pigeons[i].push_back(i);
  }

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

      int curr_nest = pigeon_nest[a - 1];
      pigeon_nest[a - 1] = b - 1;
      nest_pigeons[curr_nest].erase(remove(nest_pigeons[curr_nest].begin(), nest_pigeons[curr_nest].end(), a - 1), nest_pigeons[curr_nest].end());
      nest_pigeons[b - 1].push_back(a - 1);
      break;
    }

    case 2:
    {
      int a, b;
      cin >> a >> b;

      auto tmp = nest_pigeons[a - 1];
      nest_pigeons[a - 1] = nest_pigeons[b - 1];
      nest_pigeons[b - 1] = tmp;

      rep(i, 0, nest_pigeons[a - 1].size())
      {
        pigeon_nest[nest_pigeons[a - 1][i]] = a - 1;
      }
      rep(i, 0, nest_pigeons[b - 1].size())
      {
        pigeon_nest[nest_pigeons[b - 1][i]] = b - 1;
      }
      break;
    }

    case 3:
    {
      int a;
      cin >> a;

      cout << pigeon_nest[a - 1] + 1 << endl;
      break;
    }
    }
  }

  return 0;
}
