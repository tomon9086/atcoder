#include <iostream>
#include <complex>
using namespace std;

bool isPrime(int n) {
	if(n < 2) return false;
	bool result = true;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) result = false;
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	int count = 0;
	for(int i = 2; i <= 55555; i++) {
		if(isPrime(i) == 1 && i % 5 == 1) {
			cout << i << " ";
			count++;
		}
		if(count == n) break;
	}
	cout << endl;
	return 0;
}
