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

  vector<int> A(N);
  vector<int> B(N);
  rep(i, N) cin >> A.at(i) >> B.at(i);

  rep(i, N)
  {
    int minB = 1000000000;
    rep(j, N)
    {
      if (B.at(j) <= minB)
      {
        minB = B.at(j);
      }
    }
    rep(j, N)
    {
      if (B.at(j) <= minB)
      {
        cout << A.at(j) << " " << B.at(j) << endl;
        B.at(j) = 1000000000;
      }
    }
  }

  return 0;
}
