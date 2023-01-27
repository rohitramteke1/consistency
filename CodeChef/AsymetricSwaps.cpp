#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t; 
	while(t--) {
	    int n;
	    cin >> n;
        vector<long long int> a;

        for (int i = 0; i < 2*n; i++)
        {
            int x; cin >> x;
            a.emplace_back(x);
        }

        sort( a.begin(), a.end() );

        long long int mn = a[n-1] - a[0];
        for (int i = 0; i <= n; i++)
            mn = min( a[n-1 + i] - a[i] , mn);

        cout << mn << endl;
	}
	return 0;
}