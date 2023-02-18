// Stock span problem - EASY
#include <bits/stdc++.h>
using namespace std;

// O(N^2) + O(N)
vector<int> solve(vector<int> & arr, int n) {
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        for(; j >= 0; --j) {
            if(arr[j] > arr[i]) {
                result.emplace_back(i - j);
                break;
            }
        }
        if(j < 0)
            result.emplace_back(i + 1);
    }
    return result;
}

// O(N) + O(2*N)
vector<int> optmised(vector<int> & arr, int n) {
    vector<int> result;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while(!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        if(s.empty())
            result.emplace_back(i + 1);
        else
            result.emplace_back(i - s.top());
        s.push(i);
    }
    return result;
}



int main()
{
    vector<int> arr = {10, 4, 5, 90, 120, 80};
    int n = arr.size();
    vector<int> v = optmised(arr, n);
    
    for (auto &&i : v)
        cout << i << ' ';
    
    return 0;
}

// ○     ○
//  (• •)
// {     }
//   V V
// -------