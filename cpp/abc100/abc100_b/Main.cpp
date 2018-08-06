#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int d, n;
	cin >> d >> n;
	int count = 0;
	int ret = 0;
	for(int i = 0; count <= n;i += pow(100, d)) {
		ret = i;
		count++;
	}
	cout << ret << endl;
	return 0;
}
