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

#include <cstdio>

typedef long long ll;

#define rep(i, begin, end) for (ll i = (begin); i < (end); i++)
#define print_pair(pair) cout << "{" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

vector<int> f(int n, vector<int> a)
{
  vector<int> ret;
  int prev = -1;
  rep(i, 0, n)
  {
    if (prev < 0)
    {
      if (i == n - 1)
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
      if (i == n - 1)
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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // auto start = chrono::high_resolution_clock::now();

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n)
  {
    // cin >> a[i];
    scanf("%d", &a[i]);
  }

  // auto stop = chrono::high_resolution_clock::now();
  // // cout << chrono::duration_cast<chrono::nanoseconds>(stop - start).count() << endl;

  // start = chrono::high_resolution_clock::now();

  // int count = 0;
  while (true)
  {
    // count++;
    // print_vec(int, a);
    int n = a.size();
    auto ret = f(n, a);
    if (ret.size() == n)
    {
      break;
    }

    a = ret;
  }

  // stop = chrono::high_resolution_clock::now();
  // // cout << chrono::duration_cast<chrono::nanoseconds>(stop - start).count() << endl;

  // cout << count << endl;
  cout << a.size() << endl;
  return 0;
}
