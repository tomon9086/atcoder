#include <iostream>
#include <math.h>
using namespace std;

int degsum(int n) {
	int sum = 0;
	for(int i = 0;; i++) {
		if(n < 1) break;
		// cout << "degsum: " << n % 10 << endl;
		sum += n % 10;
		n = (int)(n / 10);
	}
	return sum;
}

int deg(int n) {
	int count = 0;
	for(int i = 0; ; i++) {
		if(n < 1) break;
		n = (int)(n / 10);
		count++;
	}
	return count;
}

bool isSnuke(int n) {
	bool ret;
	return false;
}

int main() {
	int k;
	cin >> k;
	int count = 0;
	for(long i = 1; i <= k; i++) {
		if(i < 10) cout << i << endl;
		else {
			cout << "1";
			if(i > 10) cout << "0";
			for(long j = 0; j < count + 1; j++) {
				cout << "9";
			}
			cout << endl;
			count++;
		}
	}
	return 0;
}
