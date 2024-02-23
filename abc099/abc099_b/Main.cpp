#include <iostream>
using namespace std;

int f(int n) {
	return ((n + 1) * n) / 2;
}

int main() {
	int a, b;
	cin >> a >> b;
	int n = b - a;
	cout << f(n) - b << endl;
	return 0;
}
