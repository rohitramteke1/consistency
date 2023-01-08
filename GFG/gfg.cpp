#include <bits/stdc++.h>
using namespace std;

int minLaptops(int N, int start[], int end[]) {
    // Code here
    vector< vector<int> > v( N, vector<int> (2, 0) );
    for(int i=0; i<N; i++) {
        v[i][0] = start[i];
        v[i][1] = end[i];
    }
    sort(v.begin(), v.end(), [](vector<int> &v1, vector<int> &v2) {return v1[1]<v2[1];});

    for (auto &&i : v)
    {
        cout << i[0] << ' ' << i[1] << endl;
    }

    int ans = 1;
    vector<int> prev = v[0];
    for(int i=1; i<N; ++i) {
        if(prev[1] > v[i][0]) {
            prev = v[i];
        }
        else {
            ans++;
        }
    }
    
    return ans ;
}

int main()
{
    int N = 3;
    int start[] = {1, 5, 2};
    int end[] = {2, 6, 3};

    cout << minLaptops(N, start, end) << endl;
    
    
    return 0;
}