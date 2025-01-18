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

  size_t head = 0;
  vector<pair<ll, int>> snake_head_lengths(0);
  rep(_, 0, q)
  {
    int type;
    cin >> type;
    switch (type)
    {
    case 1:
    {
      int l;
      cin >> l;

      auto last_snake = snake_head_lengths.size() > 0 ? snake_head_lengths.back() : make_pair<ll, int>(0, 0);
      snake_head_lengths.push_back({last_snake.first + last_snake.second, l});
      break;
    }
    case 2:
    {
      head++;
      break;
    }
    case 3:
    {
      int k;
      cin >> k;

      // cout << "k: " << k << ", head: " << head << endl;

      auto head_snake = snake_head_lengths[head];
      auto kth_snake = snake_head_lengths[head + k - 1];
      cout << kth_snake.first - head_snake.first << endl;
      break;
    }
    }

    // rep(i, 0, snake_head_lengths.size())
    // {
    //   cout << i << ": ";
    //   print_pair(snake_head_lengths[i]);
    // }
    // cout << endl;
  }

  return 0;
}
