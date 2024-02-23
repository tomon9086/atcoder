#include <iostream>
using namespace std;

int main() {
	int N, C;
	cin >> N, C;
	int d[C][C];
	for(int i = 0; i < C; i++) {
		for(int j = 0; j < C; j++) {
			cin >> d[i][j];
		}
	}
	int c[N][N];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> c[i][j];
		}
	}
	
	return 0;
}
