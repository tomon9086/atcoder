#include <iostream>
using namespace std;

int distance(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	if(dx < 0) dx = x1 - x2;
	if(dy < 0) dy = y1 - y2;
	return dx + dy;
}
int main() {
	int n;
	cin >> n;
	int txy[n + 1][3];
	txy[0][0] = 0;
	txy[0][1] = 0;
	txy[0][2] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> txy[i][0] >> txy[i][1] >> txy[i][2];
	}
	// for(int i = 0; i <= n; i++) {
	// 	cout << txy[i][0] << ", " << txy[i][1] << ", " << txy[i][2] << endl;
	// }
	string ret = "Yes";
	for(int i = 1; i <= n; i++) {
		int d = distance(txy[i - 1][1], txy[i - 1][2], txy[i][1], txy[i][2]);
		int dt = txy[i][0] - txy[i - 1][0];
		bool check = false;
		for(int i = 0; 2 * i <= dt; i++) {
			if(d == dt - (i * 2)) check = true;
		}
		if(!check) ret = "No";
	}
	cout << ret << endl;
	return 0;
}
