#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int half = (int)n / 2 + n % 2;
	int cursor_a = half;
	int cursor_b = half;
	if(n % 2 == 0) cursor_b++;
	int count = 0;
	for(int i = 0; i < half; i++) {
		int index[] = { 0, 0 };
		for(int j = 0; j < n; j++) {
			if(p[j] == cursor_a - 1) index[0] = j;
			if(p[j] == cursor_b + 1) index[1] = j;
		}
		if(find(p.begin(), p.begin() + n, cursor_a) < index[0]) {
			int med = p[index[0]];
			for(int k = 0; k < index[0]; k++) {
				p[k + 1] = p[k];
			}
			p[0] = med;
			count++;
		}
		if(find(p.begin(), p.begin() + n, cursor_b) > index[1]) {
			int med = p[index[1]];
			for(int k = index[1]; k < n - 1; k++) {
				p[k + 1] = p[k];
			}
			p[0] = med;
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
