#include <bits/stdc++.h>
using namespace std;

vector<int> ans(int arr[], int n) {
    stack<int> s;
    vector<int> v(n);
    for (int i = n - 2; i >= 0; i--)
    {
        if(arr[i] < arr[i+1]) {
            s.push(arr[i+1]);
            v[i] = arr[i+1];
        }
        else if(arr[i] >= arr[i+1])
        {
            while (!s.empty() && arr[i] >= s.top())
            {
                s.pop();
            }
            if(s.empty()) 
                v[i] = -1;
            else 
                v[i] = s.top();
        }
    }
    v[n-1] = -1;
    return v;
}

int main()
{
    int arr[] = {1,2,3,4};
    int n = 4;
    vector<int> v = ans(arr, n);
    for (auto &&i : v)
    {
        cout << i << ' ';
    }
    
    return 0;
}