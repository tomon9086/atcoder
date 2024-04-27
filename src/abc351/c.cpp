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

vector<int> f(vector<int> a)
{
  vector<int> ret;
  int prev = -1;
  rep(i, 0, a.size())
  {
    if (prev < 0)
    {
      if (i == a.size() - 1)
      {
        ret.push_back(a[i]);
      }

      prev = a[i];
    }
    else if (prev == a[i])
    {
      ret.push_back(prev + 1);
      prev = -1;
    }
    else
    {
      ret.push_back(prev);
      if (i == a.size() - 1)
      {
        ret.push_back(a[i]);
      }
      prev = a[i];
    }
  }

  return ret;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }

  while (true)
  {
    auto ret = f(a);
    if (ret.size() == a.size())
    {
      break;
    }

    a = ret;
  }

  cout << a.size() << endl;
  return 0;
}
