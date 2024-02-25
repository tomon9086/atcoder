#include <iostream>
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

int main() {
	int n;
	cin >> n;
	string ret = "No";
	// cout << degsum(n) << endl;
	if(n % degsum(n) == 0) ret = "Yes";
	cout << ret << endl;
	return 0;
}
