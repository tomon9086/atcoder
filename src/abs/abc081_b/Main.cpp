#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int min;
	for(int i = 0; i < n; i++) {
		if(i == 0 || a[i] < min) min = a[i];
	}
	int length = sizeof(a) / sizeof(a[0]);
	int count = 0;
	for(int i = 1; i <= min; i *= 2) {
		bool check = true;
		for(int j = 0; j < length; j++) {
			if(a[j] % 2 != 0) {
				check = false;
				cout << count << endl;
				return 0;
			}
		}
		if(check) {
			count++;
			for(int j = 0; j < length; j++) {
				a[j] /= 2;
			}
		}
	}
	return 0;
}
