#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(a > b) {
		if(a > c) cout << a * 10 + b + c;
		else cout << c * 10 + b + a;
	} else {
		if(b > c) cout << b * 10 + a + c;
		else cout << c * 10 + b + a;
	}
	cout << endl;
	return 0;
}
