#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)

#define print_vec(v)                                           \
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  sort(a.begin(), a.end());

  int count_max = 1;
  int count_max_a = a.at(0);
  int count = 1;
  rep(i, n - 1)
  {
    if (a.at(i) == a.at(i + 1))
    {
      count++;
    }
    else
    {
      count = 1;
    }

    if (count_max < count)
    {
      count_max = count;
      count_max_a = a.at(i);
    }
  }

  cout << count_max_a << " " << count_max << endl;

  return 0;
}
