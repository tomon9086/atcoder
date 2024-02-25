#include <iostream>
using namespace std;

int main()
{
  int x, a, b;
  cin >> x >> a >> b;

  // 1. xに1を足した値
  x++;
  cout << x << endl;

  // 2. (1.で出力した値)に(a+b)を掛けた値
  int ans2 = x * (a + b);
  cout << ans2 << endl;

  // 3. (2.で出力した値)に(2.で出力した値)を掛けた値
  int ans3 = ans2 * ans2;
  cout << ans3 << endl;

  // 4. (3.で出力した値)から1を引いた値
  cout << ans3 - 1 << endl;

  return 0;
}
