#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string s;
	long long k;
	cin >> s >> k;
	double sum = 0;
	for(int i = 0; i < s.length(); i++) {
		int n = s[i] - '1' + 1;
		sum += 5000000000000001.0 * log((double)n);
		if(log((double)k) <= sum) {
			cout << n << endl;
			break;
		}
		// sum += log(5000000000000001.0) + log((double)n);
		// if(log(log((double)k)) <= sum) {
		// 	cout << n << endl;
		// 	break;
		// }
	}
	return 0;
}
