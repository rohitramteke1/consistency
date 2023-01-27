#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<long long int> & v) {
    for (int i = 1; i < v.size(); i++)
    {
        if(v[i-1] > v[i]) return false;
    }
    return true;
}

int noOfSwaps(vector<long long> &a, vector<long long> &b, int n) {
    long long mn_value = b[n-1];
    int index = n;
    long long swaps = 0; 
    for (int i = 0; i < index; i++)
    {
        if(a[i] > mn_value) {
            swaps += index - i;
            index++;
        }
    }
    return swaps;
}

int main() {
	// your code goes here
	int t; cin >> t; 
	while(t--) {
	    int n;
	    cin >> n;
        vector<long long int> a(2*n);
        vector<long long int> b(2*n);

        for (int i = 0; i < 2*n; i++)
        {
            cin >> a[i];
        }

        b = a;
        sort( b.begin(), b.end() );

        long long mn_value = b[n-1];
        int index = n;
        long long swaps = 0; 
        for (int i = 0; i < index; i++)
        {
            if(a[i] > mn_value) {
                swaps += index - i;
                index++;
            }
        }
        cout << swaps << endl;
	}
	return 0;
}