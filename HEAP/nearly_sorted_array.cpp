#include <bits/stdc++.h>
using namespace std;

// TC: O(N * logK)
// SC: O(K) + O(result)
vector <int> nearlySorted(int arr[], int n, int k){
    vector<int> result;
    // Min-Heap
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(int i=0; i<n; ++i) {
        pq.push( arr[i] );
        if( pq.size() > k ) {
            result.push_back( pq.top() );
            pq.pop();
        }
    }
    while( !pq.empty() ) {
        result.push_back( pq.top() );
        pq.pop();
    }
    
    return result;
}
int main()
{
    int n = 7, k = 3;
    int arr[] = {6,5,3,2,8,10,9};
    
    vector<int> result = nearlySorted(arr,  n, k);

    for (auto &&i : result)
        cout << i << ' ';
    

    return 0;
}