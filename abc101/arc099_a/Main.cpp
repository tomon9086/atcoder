#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int count = 0;
	// if(n <= k) count = 1;
	// else {
	// 	int add = 0;
	// 	if(n % k == 0) add = 1;
	// 	count = (int)((n - 1) / (k)) + add + 1;
	// }
	for(int i = 0; n > 0; i++) {
		if(i == 0) n -= k;
		else n -= k - 1;
		count++;
	}
	cout << count << endl;
	return 0;
}
