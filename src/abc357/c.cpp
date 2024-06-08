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

int h(int n)
{
  return pow(3, n);
}

int w(int n)
{
  return h(n);
}

void sierpinski(vector<vector<char>> *buffer, int n, int x, int y)
{
  if (n == 0)
  {
    // cout << "x: " << x << ", y: " << y << endl;
    buffer->at(y)[x] += '#' - '.';
    return;
  }

  sierpinski(buffer, n - 1, x - w(n - 1), y - h(n - 1));
  sierpinski(buffer, n - 1, x, y - h(n - 1));
  sierpinski(buffer, n - 1, x + w(n - 1), y - h(n - 1));
  sierpinski(buffer, n - 1, x - w(n - 1), y);
  sierpinski(buffer, n - 1, x + w(n - 1), y);
  sierpinski(buffer, n - 1, x - w(n - 1), y + h(n - 1));
  sierpinski(buffer, n - 1, x, y + h(n - 1));
  sierpinski(buffer, n - 1, x + w(n - 1), y + h(n - 1));
}

int main()
{
  int n;
  cin >> n;

  vector<vector<char>> buffer = vector<vector<char>>(h(n), vector<char>(w(n), '.'));

  sierpinski(&buffer, n, w(n) / 2, h(n) / 2);

  rep(i, 0, buffer.size())
  {
    rep(j, 0, buffer.at(i).size())
    {
      cout << buffer.at(i)[j];
    }
    cout << endl;
  }
  return 0;
}
