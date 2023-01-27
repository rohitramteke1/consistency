#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	 while(t--) {
        int n, y;
        cin >> n >> y;
        int zor = 0;
        for(int i=0; i<n; i++) {
            int a; cin >> a;
            zor |= a;
        }
        
        int x = y - zor;
        if((x & y) == x) {
            cout << x << endl;
        }
        else {
            cout << -1 << endl;
        }
	}
	return 0;
}