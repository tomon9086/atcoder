#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int max;
	if(a + b > a - b) max = a + b;
	else max = a - b;
	if(max < a * b) max = a * b;
	cout << max << endl;
	return 0;
}
