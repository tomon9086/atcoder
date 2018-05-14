#include <iostream>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	int sum = 0;
	for(int i = 1; i <= n; i++) {
		int s = 0;
		int m = i;
		for(;m >= 1; m = (int)(m / 10)) {
			s += m % 10;
		}
		if(a <= s && s <= b) sum += i;
	}
	cout << sum << endl;
	return 0;
}
