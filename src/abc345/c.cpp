#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, begin, end) for (ll i = (begin); i < (end); i++)
#define print_pair(pair) cout << "{}" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  string s;
  cin >> s;

  sort(s.begin(), s.end());
  vector<int> count(26, 0);
  rep(i, 0, s.size())
  {
    int count_i = s.at(i) - 'a';
    count.at(count_i)++;
  }

  int mojishu = 0;
  rep(i, 0, 26)
  {
    if (count.at(i) > 0)
    {
      mojishu++;
    }
  }

  if (mojishu == 1)
  {
    cout << 1 << endl;
    return 0;
  }

  int sum = 0;
  rep(i, 0, 26) rep(j, 0, 26)
  {
    if (j != i && count.at(i) > 0)
    {
      sum += count.at(j);
    }
  }

  cout << sum / 2 << endl;
  // print_vec(int, count);
  return 0;
}
