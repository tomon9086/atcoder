#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int ret = 0;
	for(int i = 0; i < 4; i++) {
		if(s[i] == '+') ret++;
		if(s[i] == '-') ret--;
	}
	cout << ret << endl;
	return 0;
}
