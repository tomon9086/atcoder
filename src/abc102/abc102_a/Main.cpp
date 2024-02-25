#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = n; ; i *= 2) {
		if(i % 2 == 0 && i % n == 0) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
