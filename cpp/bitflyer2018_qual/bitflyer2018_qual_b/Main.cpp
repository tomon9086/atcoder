#include <iostream>
using namespace std;

int main() {
	int a, b, n;
	string x;
	cin >> a >> b >> n >> x;
	for(int i = 0; i < n; i++) {
		char c = x[i];
		switch(c) {
			case 'S':
				if(a > 0) a--;
				break;
			case 'C':
				if(b > 0) b--;
				break;
			case 'E':
				if(a >= b) {
					if(a > 0) a--;
				} else {
					if(b > 0) b--;
				}
				break;
			default:
				break;
		}
	}
	cout << a << endl << b << endl;
	return 0;
}
