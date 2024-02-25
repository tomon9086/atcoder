#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> data(5);
  for (int i = 0; i < 5; i++)
  {
    cin >> data.at(i);
  }

  // dataの中で隣り合う等しい要素が存在するなら"YES"を出力し、そうでなければ"NO"を出力する
  string result = "NO";
  for (uint i = 1; i < data.size(); i++)
  {
    if (data.at(i - 1) == data.at(i))
    {
      result = "YES";
    }
  }

  cout << result << endl;

  return 0;
}
