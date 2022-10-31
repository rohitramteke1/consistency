#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

void prefixSum(vector<int> &arr) {
    int prefix[arr.size()];
    int suffix[arr.size()];
    prefix[0] = 0;
    suffix[arr.size()-1] = 0;

    for (int i = 1; i <arr.size(); i++)
        prefix[i] = arr[i] - arr[i-1];

    for (int i = arr.size()-2; i >=0 ; i--)
        suffix[i] = arr[i+1] - arr[i];

    for (auto &&i : prefix)
        cout << i << ' ';

    cout <<endl;

    for (auto &&i : suffix)
        cout << i << ' ';

    cout << endl ;

    for (int i = 0; i <arr.size(); i++)
        cout << max(prefix[i], suffix[i]) << ' ';
    
    
    return;
}

int main()
{
    vector<int> arr = {3, 3, 4, 6, 7, 10, 10, 12, 15};
    prefixSum(arr);
    
    return 0;
}