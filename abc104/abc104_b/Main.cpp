#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	bool c = false;
	for(int i = 0; i < s.length(); i++) {
		if(i == 0 && s[i] != 'A') {
			cout << "WA" << endl;
			return 0;
		}
		if((i >= 2 && i <= s.length() - 2) && s[i] == 'C') {
			if(c) {
				cout << "WA" << endl;
				return 0;
			}
			c = true;
		} else {
			// cout << s[i] << endl;
			if(i != 0 && (s[i] < 'a' || s[i] > 'z')) {
				cout << "WA" << endl;
				return 0;
			}
		}
	}
	if(!c) {
		cout << "WA" << endl;
		return 0;
	}
	cout << "AC" << endl;
	return 0;
}
