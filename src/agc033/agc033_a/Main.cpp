#include <iostream>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	char a[h][w];
	char b[h][w];
	for(int i = 0; i < h; i++) {
		cin >> a[i];
	}
	
	int count = 0;
	for(;;) {
		count++;
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				// char t = 0, b = 0, r = 0, l = 0;
				if(a[i][j] == '.') {
					b[i][j] = '.';
					continue;
				}
				b[i][j] = '#';
				if(i - 1 >= 0) {
					// t = a[i - 1][j];
					b[i - 1][j] = '#';
				}
				if(i + 1 < h) {
					// b = a[i + 1][j];
					b[i + 1][j] = '#';
				}
				if(j - 1 >= 0) {
					// t = a[i][j - 1];
					b[i][j - 1] = '#';
				}
				if(j + 1 < w) {
					// t = a[i][j + 1];
					b[i][j + 1] = '#';
				}
			}
		}
		bool fin = 1;
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				char hoge = b[i][j];
				a[i][j] = hoge;
				if(count < 5)
					cout << hoge;
				if(hoge != '#')
					fin = 0;
			}
			if(count == 1)
				cout << endl;
		}
		if(fin)
			break;
	}
	cout << count << endl;

	return 0;
}

// あきらめまちた
