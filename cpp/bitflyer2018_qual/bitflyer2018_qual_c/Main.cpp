#include <iostream>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	int x[n];
	for(int i = 0; i < n; i++) cin >> x[i];
	int count = 0;
	for(int i = 0; i < n; i++) {
		// int c = 0;
		for(int k = i + 2; k < n; k++) {
			int j = k - 1;
			// 	// c++;
			// 	continue;
			// count += j - i;
			// break;
			for(int j = 0; j < (k - i + 1) % 2 + 1; j++) {
				if(x[k] - x[i] <= 2 * d
					&& x[j] - x[i] <= d
					&& x[k] - x[j] <= d
					&& x[k] - x[i] > d) {
					count += ;
					// やーめたっ
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}
