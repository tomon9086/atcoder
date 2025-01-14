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

const int INF = 1e7;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n - 1), b(n - 2);
  rep(i, 0, n - 1) cin >> a[i];
  rep(i, 0, n - 2) cin >> b[i];

  vector<int> weight(n, INF);
  rep(i, 0, n)
  {
    if (i == 0)
    {
      weight[i] = 0;
      continue;
    }

    int w_a = weight[i - 1] + a[i - 1];
    int w_b = i > 1 ? weight[i - 2] + b[i - 2] : INF;
    weight[i] = min(w_a, w_b);
  }

  // print_vec(int, weight);

  cout << weight[n - 1] << endl;
  return 0;
}
