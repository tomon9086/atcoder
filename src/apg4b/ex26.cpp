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
typedef vector<int> Vec;
typedef pair<string, Vec> VecVar;

vector<IntVar> int_map;
vector<VecVar> vec_map;

// 問題文の形式でvec値を出力
void print_vec(Vec vec)
{
  cout << "[ ";
  rep(i, (ll)vec.size())
  {
    cout << vec.at(i) << " ";
  }
  cout << "]" << endl;
}

int calcInt(int lhs, char op, int rhs)
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

int findIntVar(string token)
{
  rep(i, (ll)int_map.size())
  {
    if (int_map.at(i).first == token)
    {
      return int_map.at(i).second;
    }
  }

  cerr << "unexpected identifier: " << token << endl;
  return 0;
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
      int_expr = calcInt(int_expr, op, n);
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
      int_expr = calcInt(int_expr, op, findIntVar(token));
      op = 0;
    }
  }

  return int_expr;
}

Vec calcVec(Vec lhs, char op, Vec rhs)
{
  if (op == 0)
  {
    return rhs;
  }
  else if (op == '+')
  {
    rep(i, (ll)lhs.size()) lhs.at(i) += rhs.at(i);
    return lhs;
  }
  else if (op == '-')
  {
    rep(i, (ll)lhs.size()) lhs.at(i) -= rhs.at(i);
    return lhs;
  }
  else
  {
    return lhs;
  }
}

Vec findVecVar(string token)
{
  rep(i, (ll)vec_map.size())
  {
    if (vec_map.at(i).first == token)
    {
      return vec_map.at(i).second;
    }
  }

  cerr << "unexpected identifier: " << token << endl;
  return {};
}

Vec parseVecExpr()
{
  string token;
  Vec vec_expr;
  int n;
  char op = 0;
  while (true)
  {
    cin >> token;

    if (token == ";")
    {
      return vec_expr;
    }
    else if (token == "[")
    {
      Vec v;
      while (true)
      {
        cin >> token;
        if (token == "]")
        {
          break;
        }

        try
        {
          n = stoi(token);
          v.push_back(n);
        }
        catch (const std::exception &e)
        {
          if (token == ",")
          {
            continue;
          }
          else
          {
            v.push_back(findIntVar(token));
          }
        }
      }

      vec_expr = calcVec(vec_expr, op, v);
      op = 0;
    }
    else if (token == "+")
    {
      op = '+';
    }
    else if (token == "-")
    {
      op = '-';
    }
    else
    {
      vec_expr = calcVec(vec_expr, op, findVecVar(token));
      op = 0;
    }
  }

  return vec_expr;
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
      else if (token == "vec")
      {
        string identifier;
        cin >> identifier;
        cin >> gomi;

        vec_map.push_back({identifier, parseVecExpr()});
        break;
      }
      else if (token == "print_int")
      {
        cout << parseIntExpr() << endl;
        break;
      }
      else if (token == "print_vec")
      {
        print_vec(parseVecExpr());
        break;
      }

      // cout << int_map.at(0).first << "=" << int_map.at(0).second << endl;
      print_vec(vec_map.at(0).second);
      // cout << token << endl;
    }
  }
  return 0;
}
