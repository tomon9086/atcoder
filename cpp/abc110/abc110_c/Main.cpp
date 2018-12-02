#include <iostream>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int alp_s[26];	// i: sc, alp_s[i]: tc
	// int alp_t[26];
	for(int i = 0; i < 26; i++) alp_s[i] = -1;
	// for(int i = 0; i < 26; i++) alp_t[i] = 0;
	// for(int i = 0; i < s.length(); i++) alp_s[s[i] - 'a']++;
	// for(int i = 0; i < t.length(); i++) alp_t[t[i] - 'a']++;
	
	bool flag = true;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == t[i]) continue;
		int sc = s[i] - 'a';
		int tc = t[i] - 'a';
		if(alp_s[sc] != -1 && alp_s[sc] != tc) {
			cout << "No";
			flag = false;
			break;
		}
		if(alp_s[tc] != -1 && alp_s[tc] != sc) {
			cout << "No";
			flag = false;
			break;
		}
		alp_s[sc] = tc;
		alp_s[tc] = sc;
		cout << (char)(sc + 'a') << "->" << (char)(tc + 'a') << endl;
	}
	if(flag) cout << "Yes";
	cout << endl;
	return 0;
}
