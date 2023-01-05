#include <bits/stdc++.h>
using namespace std;

vector<int> factors(int n) {
    int _sqrt = sqrt(n);
    vector<int> v;
    for (int i=1; i<= _sqrt; i++)
    {
        if (n%i == 0)
        {
            if (n/i != n &&n/i == i)
                v.push_back(i);
            else
            {
                if(n/i != n)
                {
                    v.push_back(i);
                    v.push_back(n/i);
                }
            }
        }
    }
    sort( v.begin(), v.end() );

    return v;
}

int main() {

    int n = 30;
    factors(n);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v = factors(n);
        if(v.size() == 0 || v.size() == 1 || v.size() == 2) cout << -1 << endl;
        else {
            int a = v[0];
            int b = n/a;
            int c = b/v[2];
            b = b / v[1];
            // cout << a << ' ' << c << ' ' << b << endl; 
            if(a * b * c == n) {
                cout << a << ' ' << b << ' ' << c << endl;
            }
            else {
                cout << -1 << endl;
            }
        }        
    }
	return 0;
}