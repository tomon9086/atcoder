#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int min = 1000000000;
	int max = 0;
	// int a[n];
	for(int i = 0; i < n; i++) {
		// cin >> a[i];
		int a;
		cin >> a;
		if(min > a) min = a;
		if(max < a) max = a;
	}
	cout << max - min << endl;
	return 0;
}
