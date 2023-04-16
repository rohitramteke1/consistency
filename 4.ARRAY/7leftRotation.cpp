#include <bits/stdc++.h>
using namespace std;

void leftRotate(vector<int> &arr, int k) {
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

void trick(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> v(arr.begin() + k, arr.end() );
    // 1 2 3 4 5

    for (int i = 0; i < k; i++)
    {
        v.push_back(arr[i]);
    }
    
    for (auto &&i : v)
    {
        cout << i << ' ';
    }
}


// brute force
void rotateByOne(vector<int> &arr) {
    int temp = arr[0];
    int n = arr.size();
    for(int i=1; i<n; i++) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

void brute(vector<int> &arr, int k) {
    for (int i = 0; i < k; i++)
        rotateByOne(arr);

    for (auto &&i : arr)
        cout << i << ' ';
}

// better
void better(vector<int> &arr, int k) {
    int n = arr.size();

    vector<int> v(arr.begin() + k, arr.end());
    for (int i = 0; i < k; i++)
        v.push_back(arr[i]);
    
    for (auto &&i : v)
        cout << i << ' ';
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    // 1 2 3 4 5
    // 5 1 2 3 4
    // 4 5 1 2 3

    // 5 4 3 2 1
    // 1 2 3 4 5
    // 3 2 1 4 5
    // 3 2 1 5 4

    better(arr, 3);
    return 0;
}