#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)

#define print_vec(v)                                           \
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<pair<int, int>> AB(N);
  rep(i, N) cin >> AB.at(i).second >> AB.at(i).first;

  sort(AB.begin(), AB.end());

  rep(i, N) cout << AB.at(i).second << " " << AB.at(i).first << endl;

  return 0;
}
