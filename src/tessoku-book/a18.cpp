#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, begin, end) for (ll i = (begin); i < (end); i++)
#define print_pair(pair) cout << "{" << pair.first << ", " << pair.second << "}" << endl
#define print_vec(type, v)                                      \
  copy(v.begin(), v.end(), ostream_iterator<type>(cout, ", ")); \
  cout << endl;

using namespace std;

int main()
{
  int n, s;
  cin >> n >> s;
  vector<int> a(n + 1);
  rep(i, 1, n + 1) cin >> a[i];

  vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
  dp[0][0] = true;
  rep(j, 1, s + 1) dp[0][j] = false;

  // A_1 ~ A_i のカード（1 <= i <= N; i枚）からいくつか選んで合計を j にできるか？
  rep(i, 1, n + 1) rep(j, 0, s + 1)
  {
    // A_1 ~ A_{i - 1} のカード（i - 1 枚）ですでに合計が j になっている場合（A_i はいらない）
    if (dp[i - 1][j])
      dp[i][j] = true;
    // A_1 ~ A_{i - 1} のカード（i - 1 枚）で合計を (j - A_i) にできる場合（A_i を加えて合計が j になる）
    // j - a[i] < 0 はセグフォなので気をつける
    if (j >= a[i] && dp[i - 1][j - a[i]])
      dp[i][j] = true;
  }

  // rep(i, 0, n + 1)
  // {
  //   cout << i << ": ";
  //   print_vec(bool, dp[i]);
  // }

  if (dp[n][s])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
