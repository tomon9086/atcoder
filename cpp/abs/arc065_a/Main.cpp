#include <iostream>
using namespace std;

int main() {
	string s;
	// cin >> s;
	getline(cin, s);
	string parts[] = { "dream", "dreamer", "erase", "eraser" };
	int nof_parts = sizeof(parts) / sizeof(parts[0]);
	// bool match[nof_parts];
	// int cursor[nof_parts];
	// for(int i = 0; i < nof_parts; i++) {
	// 	match[i] = true;
	// }
	string ret = "NO";
	for(int k = nof_parts - 1; k >= 0; k--) {
		int count = 0;
		string part = parts[k];
		// cout << "running: " << part << endl;
		int partlen = part.length();
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == part[count]) count++;
			else {
				count = 0;
				if(s[i] == part[count]) count++;
			}
			// cout << s[i] << " " << count << endl;
			if(count == partlen) {
				for(int n = 0; n < partlen; n++) {
					// s[i - partlen + n + 1] = NULL;
					s[i - partlen + n + 1] = '\0';
				}
				// cout << s << endl;
				count = 0;
			}
		}
	}
	bool isEmpty = true;
	for(auto v: s) {
		// if(v != NULL) isEmpty = false;
		if(v != '\0') isEmpty = false;
	}
	if(isEmpty) ret = "YES";
	cout << ret << endl;
	return 0;
}
