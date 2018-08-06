#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int max = 0;
	for(int i = 1; i < n - 1; i++) {
		string chars = "";
		int count = 0;
		for(int k = 0; k < i; k++) {
			for(int l = i; l < n; l++) {
				bool flag = false;
				for(int j = 0; j < chars.size(); j++) {
					// cout << "chars :" << chars[j] << endl;
					if(s[k] == chars[j] || s[l] == chars[j]) flag = true;
				}
				// if(s[k] == s[l]) cout << "s[k] == s[l]: " << s[k] << endl;
				if(!flag && s[k] == s[l]) {
					chars += s[k];
					count++;
				}
			}
		}
		if(max < count) max = count;
		// cout << "count " << i << ": " << count << endl;
		// cout << "chars " << i << ": " << chars << endl;
	}
	cout << max << endl;
	return 0;
}
