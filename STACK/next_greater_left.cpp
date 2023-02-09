// next greater to left
#include <bits/stdc++.h>
using namespace std;

void bruteForceSolution(vector<int> &arr) {
    // 4  5  2  10  8
    // -1 -1 5  -1  10
    int n = arr.size();
    // O(N ^ 2)
    for (int i = 0; i < n; ++i)
    {
        int j = i-1;
        for(; j>=0; --j) {
            if(arr[j] > arr[i])
            {
                cout << arr[j] << ' ';
                break;
            }
        }
        if(j == -1)
            cout << -1 << ' ';
    }
}

vector<int> solve(vector<int> &arr, int n) {
    vector<int> result(n, -1);
    stack<int> s;

    for(int i=0; i<n; ++i) {
        while(!s.empty() && s.top() <= arr[i] ) {
            s.pop();
        }
        if(!s.empty())
            result[i] = s.top();
        s.push(arr[i]);
    }

    return result;
}

int main()
{
    vector<int> arr = {4,5,2,10,8};
    int N = arr.size();
    // bruteForceSolution(arr);
    vector<int> v = solve(arr, N);
    
    for (auto &&i : v)
    {
        cout << i << ' ';
    }
    
    return 0;
}