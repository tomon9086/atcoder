#include <iostream>
using namespace std;

int calc(int A, string op, int B)
{

  if (op == "+")
  {
    return A + B;
  }
  else if (op == "-")
  {
    return A - B;
  }
  else if (op == "*")
  {
    return A * B;
  }
  else if (op == "/" && B != 0)
  {
    return A / B;
  }
  else
  {
    throw runtime_error("error");
  }
}

int main()
{
  int N, A;
  cin >> N >> A;

  for (int i = 0; i < N; i++)
  {
    string op;
    int B;
    cin >> op >> B;

    try
    {
      A = calc(A, op, B);
      cout << i + 1 << ":" << A << endl;
    }
    catch (const std::exception &e)
    {
      cout << "error" << endl;
      break;
    }
  }

  return 0;
}
