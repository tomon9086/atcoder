#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long> A(N);
  vector<long> S(N);
  vector<long> T(N);

  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 0; i < N - 1; i++)
  {
    cin >> S.at(i) >> T.at(i);
  }

  for (int i = 0; i < N - 1; i++)
  {
    A.at(i + 1) += (A.at(i) / S.at(i)) * T.at(i);
    // A.at(i) -= (A.at(i) / S.at(i)) * S.at(i);
  }

  cout << A.back() << endl;

  return 0;
}
