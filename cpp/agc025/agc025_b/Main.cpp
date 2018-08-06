#include <iostream>
using namespace std;

long factorial(long n) {
	long ret = 1;
	for(long i = n; i >= 1; i--) {
		ret *= i;
	}
	return ret;
}

long permutation(long n, long k) {
	long ret = 1;
	ret *= factorial(n);
	ret /= factorial(n - k);
	return ret;
}

int main() {
	// cout << permutation(5, 2) << endl;
	long n, a, b, k;
	cin >> n >> a >> b >> k;
	long count = 0;
	for(long i = 0; i <= n; i++) {
		for(long j = 0; j <= n - i; j++) {
			for(long l = 0; l <= n - i - j; l++) {
				if(a * i + (a + b) * j + b * l == k) count += permutation(n, i + j + l) / factorial(i) / factorial(j) / factorial(l);
			}
		}
	}
	cout << count % 998244353 << endl;
	return 0;
}
