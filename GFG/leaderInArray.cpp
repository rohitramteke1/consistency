#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> & arr) {
    vector<int> ans;
    int n = arr.size();
    int prev_leader = arr[n-1];
    for (int i = n - 1; i >= 0; --i)
    {
        if(arr[i] >= prev_leader) {
            ans.emplace_back(arr[i]);
            prev_leader = arr[i];
        }
    }
    reverse( ans.begin(), ans.end() );
    return ans;
}

// Brute Force
void bfs(vector<int> & arr) {
    bool flag;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        flag = true;
        for (int j = i+1; j < arr.size(); j++)
        {
            if(arr[i] < arr[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans.emplace_back(arr[i]);
            cout << arr[i] << ' ';
        }
    }
}

int main()
{
    vector<int> arr = {16,17,4,3,5,2};
    vector<int> ans = leaders(arr);
    for (auto &&i : ans)
    {
        cout << i << ' ';
    }
    cout << endl;
    bfs(arr);
    
    return 0;
}