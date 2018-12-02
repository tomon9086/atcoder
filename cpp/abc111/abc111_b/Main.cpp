#include <iostream>
#include <math.h>
using namespace std;

bool f(int n) {
    int p;
    for(int i = 0; i < 3; i++) {
        // cout << n << endl;
        if(i == 0) {
            p = n % 10;
            n /= 10;
            continue;
        } else {
            if(n % 10 != p) return false;
            n /= 10;
        }
    }
    return true;
}

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < 1000; i++) {
        if(f(n + i)) {
            cout << n + i;
            break;
        }
    }
    cout << endl;
    return 0;
}
