#include <bits/stdc++.h>
using namespace std;

long long trappingWater(int arr[], int n){
    // code here
    // O(4N) + O(1)
    vector<int> a(n, arr[0]);
    vector<int> b(n, arr[n-1]);
    
    for(int i=1; i<n; ++i) {
        a[i] = max(arr[i], a[i-1]);
        b[n-1-i] = max(arr[n-1-i], b[n-i]);
    }

    long long rain = 0;
    
    for(int i=0; i<n; ++i) 
        rain += min(b[i], a[i]) - arr[i];
    
    return rain;
}

int main()
{
    int N = 4;
    int arr[] = {7,4,0,9};
    cout << trappingWater(arr, N) << endl;
    return 0;
}