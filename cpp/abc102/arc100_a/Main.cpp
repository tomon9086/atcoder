#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int diff[n];
	for(int i = 0; i < n; i++) {
		diff[i] = a[i] - (i + 1);
	}
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += diff[i];
	}
	// cout << 1.0 * sum / n << endl;
	int b;
	double bb = 1.0 * sum / n;
	if(bb < 0) b = round(bb) - 1;
	else b = round(bb);
	int sadness = 0;
	for(int i = 0; i < n; i++) {
		sadness += abs(a[i] - (b + 1 + i));
	}
	cout << sadness << endl;
	return 0;
}
