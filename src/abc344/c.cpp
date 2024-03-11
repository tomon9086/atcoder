#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define print_pair(pair) cout << "{}" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  int n, m, l, q;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  cin >> m;
  vector<int> b(m);
  rep(i, m) cin >> b.at(i);
  cin >> l;
  vector<int> c(l);
  rep(i, l) cin >> c.at(i);
  cin >> q;
  // vector<int> x(q);
  // rep(i, q) cin >> x.at(i);

  vector<int> dekiru;
  rep(i, n) rep(j, m) rep(k, l)
  {
    dekiru.push_back(a.at(i) + b.at(j) + c.at(k));
  }

  sort(dekiru.begin(), dekiru.end());

  rep(i, q)
  {
    int x;
    cin >> x;

    auto iter = find(dekiru.begin(), dekiru.end(), x);
    if (iter == dekiru.end())
    {
      cout << "No" << endl;
    }
    else
    {
      cout << "Yes" << endl;
    }
  }

  return 0;
}
