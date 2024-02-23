#include <iostream>
using namespace std;

int main() {
	unsigned long long a, b, c, k;
	cin >> a >> b >> c >> k;
	bool flag = false;
	if(a == b) {
		cout << 0 << endl;
		return 0;
	}
	for(unsigned long long i = 0; i < k; i++) {
		unsigned long long check;
		unsigned long long meda = a;
		unsigned long long medc = c;
		check = c;
		c = a + b;
		if(c - check < 0) flag = true;

		check = a;
		a = b + medc;
		if(a - check < 0) flag = true;

		check = b;
		b = meda + medc;
		if(b - check < 0) flag = true;
	}
	long long ret = a - b;
	// cout << flag << " " << ret << endl;
	if(!flag && ret <= 1000000000000000000) cout << ret << endl;
	else cout << "Unfair" << endl;
	return 0;
}
