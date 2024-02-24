#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int A, B, C;
  cin >> A >> B >> C;

  int maxH = max(A, max(B, C));
  int minH = min(A, min(B, C));

  cout << maxH - minH << endl;

  return 0;
}
