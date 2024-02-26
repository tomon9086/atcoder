#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define print_pair(pair) cout << "{" << pair.first << ", " << pair.second << "}" << endl

using namespace std;

typedef pair<string, int> IntVar;
typedef pair<string, vector<int>> VecVar;

vector<IntVar> int_map;
vector<VecVar> vec_map;

// 問題文の形式でvec値を出力
void print_vec(vector<int> vec)
{
  cout << "[ ";
  rep(i, (ll)vec.size())
  {
    cout << vec.at(i) << " ";
  }
  cout << "]" << endl;
}

int calc(int lhs, char op, int rhs)
{
  if (op == 0)
  {
    return rhs;
  }
  else if (op == '+')
  {
    return lhs + rhs;
  }
  else if (op == '-')
  {
    return lhs - rhs;
  }
  else
  {
    return lhs;
  }
}

int parseIntExpr()
{
  string token;
  int int_expr = 0;
  char op = 0;
  while (true)
  {
    cin >> token;
    char ch = token[0];
    int n = ch - '0';
    if (0 <= n && n < 10)
    {
      int_expr = calc(int_expr, op, n);
      op = 0;
    }
    else if (ch == '+' || ch == '-')
    {
      op = ch;
    }
    else if (token == ";")
    {
      return int_expr;
    }
    else
    {
      bool isFound = false;
      rep(i, (ll)int_map.size())
      {
        if (int_map.at(i).first == token)
        {
          int_expr = calc(int_expr, op, int_map.at(i).second);
          op = 0;
          isFound = true;
          break;
        }
      }

      if (!isFound)
      {
        cerr << "unexpected identifier: " << token << endl;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;

  rep(i, n)
  {
    string token;
    string gomi;

    while (token != ";")
    {
      cin >> token;
      if (token == "int")
      {
        string identifier;
        cin >> identifier;
        cin >> gomi;

        int_map.push_back({identifier, parseIntExpr()});
        break;
      }
      else if (token == "print_int")
      {
        cout << parseIntExpr() << endl;
        break;
      }

      // cout << int_map.at(0).first << "=" << int_map.at(0).second << endl;
      // cout << token << endl;
    }
  }
  return 0;
}
