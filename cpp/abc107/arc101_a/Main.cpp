#include <iostream>
using namespace std;

int abs(int n) {
	if(n >= 0) return n;
	else return -1 * n;
	return 0;
}

int main() {
	int n, k;
	cin >> n >> k;
	int x[n];
	bool xflag[n];
	int pos = 0;
	int posi = 0;
	for(int i = 0; i < n; i++) {
		cin >> x[i];
		xflag[i] = false;
		if(x[i] <= 0) posi = i;
		// else if(x[i] == 0) pos = i;
	}
	int count = 0;
	for(int i = 0; i < k; i++) {
		bool flag = false;
		if(x[posi] == pos) {
			flag = true;
		}
		int l, r, li, ri;
		bool none = true;
		for(int j = 0; j < abs(posi); j++) {
			li = posi - j - flag;
			if(!xflag[li]) {
				l = x[li];
				none = false;
				break;
			}
		}
		if(none) {
			l = -1000000000;
			li = -1;
		}
		none = true;
		for(int j = 0; j < abs(n - posi - 1); j++) {
			ri = posi + j;
			if(!xflag[ri]) {
				r = x[ri];
				none = false;
				break;
			}
		}
		if(none) {
			r = 1000000000;
			ri = n;
		}

		if(ri < n && abs(l - pos) > abs(r - pos)) {
			cout << pos << endl;
			count += abs(r - pos);
			pos = r;
			posi = ri;
		} else if(li > -1) {
			cout << pos << endl;
			count += abs(l - pos);
			pos = l;
			posi = li;
		}
	}
	cout << count << endl;
	return 0;
}
