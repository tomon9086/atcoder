#include <iostream>
using namespace std;

int main() {
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	int x[N + 1];
	x[N] = X;
	for(int i = 0; i < N; i++) cin >> x[i];
	int y[M + 1];
	y[M] = Y;
	for(int i = 0; i < M; i++) cin >> y[i];
	int xmax, ymin;
	for(int i = 0; i < N + 1; i++) if(i == 0 || x[i] > xmax) xmax = x[i];
	for(int i = 0; i < M + 1; i++) if(i == 0 || y[i] < ymin) ymin = y[i];
	if(xmax < ymin) cout << "No War";
	else cout << "War";
	cout << endl;
	return 0;
}
