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

  int count = 0;
  char prev = 0;
  for (size_t i = 0; i < s.size(); i++)
  {
    if (prev == '0' && s[i] == '0')
    {
      prev = 0;
      continue;
    }

    prev = s[i];
    count++;
  }

  cout << count << endl;
  return 0;
}
