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

int _main(istream &cin, ostream &cout)
{
  // write your code here
  cout << "Hello, world!" << endl;
  return 0;
}

int main()
{
  std::stringstream input_buf;
  std::stringstream output_buf;
  string line;
  while (getline(cin, line))
  {
    input_buf << line << '\n';
  }

  uint32_t iteration = 10;
  vector<int64_t> results(iteration);

  for (uint32_t i = 0; i < iteration; i++)
  {
    input_buf.seekg(0);

    auto start = chrono::high_resolution_clock::now();
    int exit_code = _main(input_buf, output_buf);
    auto stop = chrono::high_resolution_clock::now();

    results.at(i) = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
  }

  int64_t sum = 0;
  for (uint32_t i = 0; i < iteration; i++)
  {
    sum += results.at(i);
  }

  double ave = (double)sum / (double)iteration;

  double med = results.at(iteration / 2);
  if (iteration % 2 == 0)
  {
    med += results.at(iteration / 2 - 1);
    med /= 2.0;
  }

  int64_t sq_diff_sum = 0;
  for (uint32_t i = 0; i < iteration; i++)
  {
    int64_t d = results.at(i) - ave;
    sq_diff_sum += d * d;
  }

  double sd = sqrt((double)sq_diff_sum / (double)iteration);

  cout << "ave: " << ave << " ns" << endl;
  cout << "med: " << med << " ns" << endl;
  cout << " sd: " << sd << endl;

  return 0;
}
