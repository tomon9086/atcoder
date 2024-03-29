#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

typedef long long ll;

#define print_vec(v)                                           \
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  string S;
  cin >> S;

  char prevprev = 0;
  char prev = 0;

  for (uint i = 0; i < S.length(); i++)
  {
    char ch = S[i];

    if (i == 0)
    {
      prevprev = ch;
      continue;
    }
    else if (i == 1)
    {
      prev = ch;
      continue;
    }

    if (ch != prev)
    {
      if (ch != prevprev)
      {
        cout << i + 1 << endl;
        break;
      }
      else
      {
        cout << i << endl;
        break;
      }
    }
    else
    {
      if (ch != prevprev)
      {
        cout << i - 1 << endl;
        break;
      }
      else
      {
        continue;
      }
    }
  }

  return 0;
}
