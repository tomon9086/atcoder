#include <iostream>
using namespace std;

int digsum(int n) {
	int sum = 0;
	while(true) {
		sum += n % 10;
		n = (int)(n / 10);
		if(n <= 0) return sum;
	}
}

int main() {
	int n;
	cin >> n;
	int min;
	for(int i = 1; i < n; i++) {
		int j = n - i;
		int sum = digsum(i) + digsum(j);
		if(i == 1 || min > sum) min = sum;
	}
	cout << min << endl;
	return 0;
}
