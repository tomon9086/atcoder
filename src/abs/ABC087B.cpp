#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define print_pair(pair) cout << "{}" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  // 500 円玉を A 枚、100 円玉を B 枚、50 円玉を C 枚
  // 硬貨の中から何枚かを選び、合計金額をちょうど X 円にする
  int a, b, c, x;
  cin >> a >> b >> c >> x;

  int count = 0;
  rep(i, a + 1) rep(j, b + 1) rep(k, c + 1)
  {
    if (x == i * 500 + j * 100 + k * 50)
    {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
