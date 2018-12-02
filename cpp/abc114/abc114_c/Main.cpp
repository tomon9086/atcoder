#include <iostream>
#include <math.h>
using namespace std;

bool judge(int n) {
	string s = to_string(n);
	// int count[3];
	// count[0] = 0;
	// count[1] = 0;
	// count[2] = 0;
	int nn = 0;
	for(int i = 0; i < s.length(); i++) {
		char c = s[i];
		if(!(c == '3' || c == '5' || c == '7'))
			return false;
		// count[(c - '3') / 2]++;
		nn += (c - '3' + 1) * pow(10, s.length() - i - 1);
	}
	// if(count[0] > 0 && count[1] > 0 && count[2] > 0)
	// 	return true;
	// else
	// 	return false;
	if(nn != 0 && nn % 15 == 0)
		return true;
	else
		return false;
}

int main() {
	int n;
	cin >> n;
	int count = 0;
	for(int i = 1; i <= n; i++) {
		if(judge(i))
			count++;
	}
	cout << count << endl;
	return 0;
}
