#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#define print_vec(v)                                           \
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", ")); \
  cout << endl;

using namespace std;

typedef long long ll;

int main()
{
  int N;
  cin >> N;

  string S;
  cin >> S;

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++)
  {
    string c, d;
    cin >> c >> d;

    for (int j = 0; j < N; j++)
    {
      if (S[j] == c[0])
      {
        S[j] = d[0];
      }
    }
  }

  cout << S << endl;

  return 0;
}
