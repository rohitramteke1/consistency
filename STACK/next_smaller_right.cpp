// Nearest smaller to right
#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForceSolution(vector<int> & arr) {
    int n = arr.size();
    vector<int> res(n, -1);

    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            if(arr[j] < arr[i]) {
                res[i] = arr[j];
                break;
            }
        }
    }
    return res;   
}

vector<int> solve(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for(int i=n-1; i >=0; --i) {
        while(!s.empty() && s.top() >= arr[i] ) {
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
    // 2 2 -1 8 -1

    vector<int> v = solve(arr);
    
    for (auto &&i : v)
    {
        cout << i << ' ';
    }
    
    return 0;
}