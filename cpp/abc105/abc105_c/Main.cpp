#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	int deg;
	deg = (int)sqrt(abs(n)) + !(n % 2);
	for(int i = deg; i >= 0; i--) {
		int m = (int)pow(-2, i);
		cout << n << ", " << m << endl;
		if(n > 0 && n > m) {
			s += '1';
			n -= m;
		} else if(n < 0 && m < 0 && n < m) {
			s += '1';
			n -= m;
		} else s += '0';
	}
	cout << s << endl;
	return 0;
}
