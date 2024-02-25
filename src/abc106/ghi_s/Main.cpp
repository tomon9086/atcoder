#include <iostream>
using namespace std;

int yakusu(int n) {
	int count = 0;
	for(int i = 1; i <= n; i++) {
		if(n % i == 0) count++;
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	int count = 0;
	for(int i = 1; i <= n; i += 2) {
		if(yakusu(i) == 8) count++;
	}
	cout << count << endl;
	return 0;
}
