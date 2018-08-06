#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int l = s.length();
	int n[l];
	for(int i = 0; i < l; i++) {
		n[i] = 0;
		if(s[i] == 'C') {
			n[i] = 1;
			continue;
		}
		int offset = 'B' - '?';
		bool ishatena = s[i] == '?';
		if(ishatena) s[i] += offset;

		char c = s[i] + 1;
		for(int k = i + 1; k < l; k++) {
			// cout << s[k] << " == " << c << endl;
			if(s[k] == c || s[k] == '?') n[i]++;
		}
		if(ishatena) s[i] -= offset;
	}
	int mod = 1000000007;
	int count = 0;
	for(int i = 0; i < l; i++) {
		// cout << s[i] << ", " << n[i] << endl;
		if(s[i] != 'A' && s[i] != '?') continue;
		for(int j = i + 1; j < l; j++) {
			if(s[j] != 'B' && s[i] != '?') continue;
			count += n[j];
			if(count >= mod) count -= mod;
		}
	}
	cout << count << endl;	// s中の'?'の個数をかけるとよさそう
	return 0;
}
