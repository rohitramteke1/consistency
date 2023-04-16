#include <bits/stdc++.h>
using namespace std;

void rightRotate(vector<int> &arr, int k) {
    int n = arr.size();
    if(k > n)
        k = k % n;

    reverse( begin(arr) + n - k, end(arr));
    reverse( begin(arr), begin(arr) + n - k);
    reverse( arr.begin(), arr.end() );

    for (auto &&i : arr)
        cout << i << ' ';
    
}

void solve(vector<int> &arr, int k) {
    int n = arr.size();

    vector<int> v(n, 0);
    k %= n;
    
    for (int i = 0; i < n; i++)
    {
        v[i] = arr[(n - k + i) % n];
    }
    for (auto &&i : v)
        cout << i << ' ';
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    // 1 2 3 4 5
    // 3 2 1 5 4
    // 4 5 1 2 3

    solve(arr, 7);
    return 0;
}