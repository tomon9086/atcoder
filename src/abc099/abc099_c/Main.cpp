#include <iostream>
#include <math.h>
using namespace std;

int mmm(int base, int n) {
	int min = 0;
	for(int i = 1; i < n; i++) {
		if(pow(base, i) > n) return min;
		min = i;
	}
	return 0;
}

int takusan(int n) {
	int max = 1;
	if(max < pow(9, mmm(9, n))) max = pow(9, mmm(9, n));
	if(max < pow(6, mmm(6, n))) max = pow(6, mmm(6, n));
	return max;
}

int main() {
	int n;
	cin >> n;
	int count = 0;
	while(n > 0) {
		int t = takusan(n);
		cout << t << endl;
		n -= t;
		count++;
	}
	cout << count << endl;
	return 0;
}

// int main() {
// 	int n;
// 	cin >> n;
// 	if(n % 9 == 0) {
// 		// cout << mmm(9, n) << endl;
// 		return 0;
// 	}
// 	if(n % 6 == 0) {
// 		// cout << mmm(6, n) << endl;
// 		return 0;
// 	}
// 	int count = 0;

// 	while(mmm(9, n) != 0 || mmm(6, n) != 0) {
// 		if(mmm(9, n) != 0) {
// 			count++;
// 			n -= pow(9, mmm(9, n));
// 			// cout << pow(9, mmm(9, n)) << endl;
// 		}

// 		if(mmm(6, n) != 0 && pow(6, mmm(6, n)) > pow(9, mmm(9, n))) {
// 			count++;
// 			n -= pow(6, mmm(6, n));
// 			// cout << pow(6, mmm(6, n)) << endl;
// 		}
// 	}

// 	count += n;
// 	// cout << n << endl;
// 	cout << count << endl;
// 	return 0;
// }
