#include <bits/stdc++.h>
using namespace std;

int connectRopes(int arr[], int n) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; ++i) 
        pq.push(arr[i]);

    int cost = 0;
    while(pq.size() >= 2) {
        int a = 0;
        int b = 0;
        if(!pq.empty())
        {
            a += pq.top();
            pq.pop();
        }
        if(!pq.empty())
        {
            b += pq.top();
            pq.pop();
        }
        cost += a + b;
        pq.push(a + b);
    }
    
    return cost;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cost = connectRopes(arr, n);
    cout << cost << endl;
    
    return 0;
}