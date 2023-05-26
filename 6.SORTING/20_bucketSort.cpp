#include <bits/stdc++.h>
using namespace std;

void bucketSort(int arr[], int n, int k) {
    // find the max value then add 1 to it for safety purpose
    // why +1 ? because when the buckets are of size k and mx
    // is equal to last-bucket range 
    // in this ex buckets are 4 and the last element is the 80
    // which will get bucket out of range
    int mx = *max_element(arr, arr + n) + 1;
    vector< int > buckets[k];
    
    // now add the elements to the buckets
    for (int i = 0; i < n; i++)
    {
        int bkt = (arr[i] * k) / mx;
        buckets[bkt].push_back(arr[i]);
    }

    // // sort the buckets
    for (int i = 0; i < k; i++)
        sort( buckets[i].begin(), buckets[i].end() ) ;
    
    int index = 0;
    
    // // copy the items from the bucket
    for (int i = 0; i < k; i++)
        for (int j = 0; j < buckets[i].size(); j++)
            arr[index++] = buckets[i][j];
    
    for (int i=0; i<n; i++)
        cout << arr[i] << ' ';
}

int main()
{
    int arr[] = {30,40,10,79,5,12,70};
    int n = sizeof(arr)/sizeof(arr[0]);

    bucketSort(arr, n, 4);
    
    return 0;
}