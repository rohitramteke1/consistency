#include <bits/stdc++.h>
using namespace std;

vector<int> kClosestElements(vector<int>arr, int n, int x, int k) {
    vector<int> result;
    priority_queue< pair<int, int> > pq;

    for (int i = 0; i < n; ++i)
    {
        int diff = abs( x - arr[i] );
        pq.push( { diff, arr[i] } );
        if(pq.size() > k) {
            pq.pop();
        }
    }
    
    while(pq.size())
    {
        result.emplace_back( pq.top().second );
        pq.pop();
    }
    return result;
}

int main()
{
    int N = 6, X = 5, K = 3;
    vector<int> arr = {10, 2, 14, 4, 7, 6};
    
    vector<int> v = kClosestElements(arr, N, X, K);

    for (auto &&i : v)
        cout << i << ' ';
    

    return 0;
}