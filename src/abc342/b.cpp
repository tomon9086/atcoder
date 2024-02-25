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

  vector<int> P(N);
  for (int i = 0; i < N; i++)
  {
    cin >> P[i];
  }

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++)
  {
    int A, B;
    cin >> A >> B;

    int Ai, Bi;
    for (int j = 0; j < N; j++)
    {
      if (P[j] == A)
      {
        Ai = j;
      }
      if (P[j] == B)
      {
        Bi = j;
      }
    }

    if (Ai > Bi)
    {
      cout << B << endl;
    }
    else if (Ai < Bi)
    {
      cout << A << endl;
    }
  }

  return 0;
}
