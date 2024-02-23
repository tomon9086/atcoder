#include <iostream>
#include <complex>
using namespace std;

bool isExp(int x) {
	if(x == 1) return true;
	for(int i = 2; i <= sqrt(x); i++) {
		if(x % i != 0) continue;
		int n = x;
		for(int j = 0; n > 1; j++) {
			n /= i;
			if(n == 1) return true;
			if(n % i != 0) break;
		}
	}
	return false;
}
int main() {
	int x;
	cin >> x;
	// cout << isExp(x);
	for(int i = x; i > 0; i--) {
		if(isExp(i)) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
