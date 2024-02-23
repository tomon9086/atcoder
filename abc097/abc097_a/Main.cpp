#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int l, m, n;
	if(c - a < 0) l = a - c;
	else l = c - a;
	if(c - b < 0) m = b - c;
	else m = c - b;
	if(b - a < 0) n = a - b;
	else n = b - a;
	if(m <= d && n <= d) {
		cout << "Yes";
	} else if(l <= d) {
		cout << "Yes";
	}else {
		cout << "No";
	}
	cout << endl;
	return 0;
}
