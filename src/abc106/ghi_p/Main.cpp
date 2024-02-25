#include <iostream>
using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	int lr[m][2];
	int pq[q][2];
	for(int i = 0; i < m; i++) {
		cin >> lr[i][0] >> lr[i][1];
	}
	for(int i = 0; i < q; i++) {
		cin >> pq[i][0] >> pq[i][1];
	}
	
	int count[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			count[i][j] = -1;
		}
	}
	for(int i = 0; i < q; i++) {
		int kukan[2];
		kukan[0] = pq[i][0];
		kukan[1] = pq[i][1];
		int count = 0;
		for(int k = 0; k < m; k++) {
			int express[2];
			express[0] = lr[k][0];
			express[1] = lr[k][1];
			if(kukan[0] <= express[0] && express[1] <= kukan[1]) count++;
		}
		cout << count << endl;
	}
	return 0;
}
