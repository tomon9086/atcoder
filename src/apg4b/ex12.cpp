#include <iostream>
using namespace std;

int main()
{
  string S;
  cin >> S;

  int sum = 0;
  char op = 0;

  for (uint i = 0; i < S.length(); i++)
  {
    char c = S[i];
    int n = c - '0';
    if (0 <= n && n <= 9)
    {
      if (op == 0)
      {
        sum = n;
      }
      else if (op == '+')
      {

        sum += n;
        op = 0;
      }
      else if (op == '-')
      {

        sum -= n;
        op = 0;
      }
    }
    else if (c == '+' || c == '-')
    {
      op = c;
    }
  }

  cout << sum << endl;

  return 0;
}
