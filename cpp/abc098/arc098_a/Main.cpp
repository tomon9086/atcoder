#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int count[n];
	for(int i = 0; i < n; i++) count[i] = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'E') for(int k = i - 1; k >= 0; k--) count[k]++;
		else for(int k = i + 1; k < n; k++) count[k]++;
	}
	int min;
	for(int i = 0; i < n; i++) {
		if(min > count[i] || i == 0) min = count[i];
	}
	cout << min << endl;
	return 0;
}
