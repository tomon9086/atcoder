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
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++)
  {
    cin >> A.at(i) >> B.at(i);
  }

  vector<vector<string>> map(N, vector<string>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      map.at(i).at(j) = "-";
    }
  }

  for (int i = 0; i < M; i++)
  {
    int a = A.at(i) - 1;
    int b = B.at(i) - 1;

    map.at(a).at(b) = "o";
    map.at(b).at(a) = "x";
  }

  for (u_long i = 0; i < map.size(); i++)
  {
    for (u_long j = 0; j < map.at(i).size(); j++)
    {
      if (j != 0)
      {
        cout << " ";
      }
      cout << map.at(i).at(j);
    }
    cout << endl;
  }

  return 0;
}
