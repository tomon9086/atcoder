#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	string result;
	if(a * b % 2 == 0) {
		result = "Even";
	} else {
		result = "Odd";
	}
	cout << result << endl;
	return 0;
}
