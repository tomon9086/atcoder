#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	// if(n != 0 && ((n % 7) % 4 == 0 || (n % 4) % 7 == 0)) cout << "Yes";
	// else cout << "No";
	bool flag = false;
	for(int i = 0; i < (n / 4) + 1; i++) {
		for(int j = 0; j < (n / 7) + 1; j++) {
			if(n == 4 * i + 7 * j) {
				flag = true;
				break;
			}
		}
		if(flag) break;
	}
	if(flag) cout << "Yes";
	else cout << "No";
	cout << endl;
	return 0;
}
