#include <algorithm>
#include <iostream>
#include <iterator>
#include <tuple>
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

  string mapping_from = "abcdefghijklmnopqrstuvwxyz";
  string mapping_to = mapping_from;

  for (int i = 0; i < Q; i++)
  {
    string c, d;
    cin >> c >> d;

    for (u_long j = 0; j < mapping_to.size(); j++)
    {
      if (mapping_to[j] == c[0])
      {
        mapping_to[j] = d[0];
      }
    }
  }

  // cout << mapping_from << endl;
  // cout << mapping_to << endl;

  for (int i = 0; i < N; i++)
  {
    uint mapping_i = mapping_from.find(S[i]);
    S[i] = mapping_to[mapping_i];
  }

  cout << S << endl;

  return 0;
}
