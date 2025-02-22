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
  string s;
  cin >> s;

  vector<char> stack(0);

  rep(i, 0, s.size())
  {
    char c = s[i];
    if (c == '(' || c == '[' || c == '<')
    {
      stack.push_back(c);
    }
    else if (c == ')')
    {
      if (stack.size() == 0 || stack.back() != '(')
      {
        cout << "No" << endl;
        return 0;
      }
      stack.pop_back();
    }
    else if (c == ']')
    {
      if (stack.size() == 0 || stack.back() != '[')
      {
        cout << "No" << endl;
        return 0;
      }
      stack.pop_back();
    }
    else if (c == '>')
    {
      if (stack.size() == 0 || stack.back() != '<')
      {
        cout << "No" << endl;
        return 0;
      }
      stack.pop_back();
    }
  }

  if (stack.size() > 0)
  {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}
