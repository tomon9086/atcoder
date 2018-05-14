#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int p[n];
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int xy[m][2];
	for(int i = 0; i < m; i++) {
		cin >> xy[i][0] >> xy[i][1];
	}
	return 0;
}
