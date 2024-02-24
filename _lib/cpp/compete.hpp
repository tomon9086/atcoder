#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

typedef long long ll;

#define print_vec(v)                                           \
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", ")); \
  cout << endl;
