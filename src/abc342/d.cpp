#include <algorithm>
#include <cmath>
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

  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  // sort(A.begin(), A.end());

  int count = 0;
  for (int i = 0; i < N; i++)
  {
    double Ai = A[i];
    if (Ai == 0)
    {
      count += N - i - 1;
      continue;
    }

    for (int j = i + 1; j < N; j++)
    {
      double Aj = A[j];

      // 愚直
      double ij_sqrt = sqrt(Ai * Aj);
      if (ij_sqrt == floor(ij_sqrt))
      {
        count++;
      }

      // ソートしたAについて、A_i で A_j を割った値が平方数なら A_i * A_j も平方数だなぁと思うなど
      // double sho = max(Ai, Aj) / min(Ai, Aj);

      // if (sho == floor(sho))
      // {
      //   double sho_sqrt = sqrt(sho);
      //   if (sho_sqrt == floor(sho_sqrt))
      //   {
      //     count++;
      //   }
      // }
    }
  }

  cout << count << endl;

  return 0;
}
