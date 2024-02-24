#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int sum = 0;
  vector<int> v(N);

  for (int i = 0; i < N; i++)
  {
    int n;
    cin >> n;

    v.at(i) = n;
    sum += n;
  }

  // 平均点が整数にならない場合、小数点以下を切り捨てた数値を平均点とします
  int ave = sum / N;

  for (int i = 0; i < N; i++)
  {
    cout << abs(v.at(i) - ave) << endl;
  }

  return 0;
}
