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

vector<char> seq = {'s', 'n', 'u', 'k', 'e'};
vector<pair<int, int>> around_rel = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

vector<pair<int, int>> search(vector<vector<char>> map, pair<int, int> pos, int seq_i, vector<pair<int, int>> pos_history)
{
  if (pos_history.size() + 1 == seq.size())
  {
    vector<pair<int, int>> new_pos_history(pos_history.size());
    copy(pos_history.begin(), pos_history.end(), new_pos_history.begin());
    new_pos_history.push_back(pos);

    return new_pos_history;
  }

  char next_ch = seq[seq_i + 1];
  vector<vector<pair<int, int>>> results(8);
  rep(a, 0, around_rel.size())
  {
    if (pos.first + around_rel[a].first >= 0 &&
        pos.second + around_rel[a].second >= 0 &&
        map[pos.first + around_rel[a].first][pos.second + around_rel[a].second] == next_ch)
    {
      vector<pair<int, int>> new_pos_history(pos_history.size());
      copy(pos_history.begin(), pos_history.end(), new_pos_history.begin());
      new_pos_history.push_back(pos);

      auto result = search(map, {pos.first + around_rel[a].first, pos.second + around_rel[a].second}, seq_i + 1, new_pos_history);
      // rep(x, 0, result.size())
      // {
      //   cout << result[x].first << ", " << result[x].second << endl;
      // }
      // cout << endl;

      results[a] = result;
    }
    else
    {
      results[a] = {};
    }
  }

  // rep(i, 0, results.size())
  // {
  //   if (results[i].size() > 0)
  //   {
  //     rep(x, 0, results[i].size())
  //     {
  //       cout << results[i][x].first << ", " << results[i][x].second << endl;
  //     }
  //     cout << endl;
  //   }
  // }
}

int main()
{
  int h, w;
  cin >> h >> w;

  vector<vector<char>> map(w, vector<char>(h));
  rep(y, 0, h)
  {
    string s;
    cin >> s;
    rep(x, 0, w)
    {
      map[x][y] = s[x];
    }
  }

  // rep(x, 0, w)
  // {
  //   print_vec(char, map[x]);
  // }

  rep(y, 0, h) rep(x, 0, w)
  {
    if (map[x][y] == seq[0])
    {
      auto result = search(map, {x, y}, 0, {});
      if (result.size() != 0)
      {
        rep(i, 0, result.size())
        {
          cout << result[i].first + 1 << " " << result[i].second + 1 << endl;
        }
        return 0;
      }
    }
  }

  puts("kai nashi");
  return 0;
}
