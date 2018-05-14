#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	for(char c: s) {
		cout << (int)c << endl;
	}
	return 0;
}
