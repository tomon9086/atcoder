#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// string v;
	// int count = 0;
	// cout << s.size();
	// for(int i = 0; i < s.size(); i++) {
	// 	char c = s[i];
	// 	if(c != ' ') {
	// 		v += c;
	// 		cout << v << " ";
	// 	} else {
	// 		a[count] = stoi(v);
	// 		count++;
	// 		cout << "\n";
	// 	}
	// }

	int max_even = 0;
	for(int i = 0; i < n; i++) {
		int v = a[i];
		if(v % 2 == 0 && v > max_even) max_even = v;
	}
	int count = 0;
	for(int k = 0; k < max_even / 2; k += 2) {
		bool can_divide = true;
		for(int i = 0; i < n; i++) {
			if(a[i] % 2 != 0) can_divide = false;
			else a[i] /= 2;
		}
		if(can_divide) count++;
		else break;
	}
	cout << count << endl;
	return 0;
}
