#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& grid) {

    int mx = INT_MIN;
    int row_mx = INT_MIN;
    int row_idx = -1;
    int ans = 0;
    int j;
    int k = 0;
    for (int i = 0; i < grid[0].size(); i++)
    {
        sort(grid[i].begin(), grid[i].end());

    
    }    
    
    
    return ans;
}

int main()
{
    vector< vector<int> > grid = { 
        {1,2,4}, {3,3,1} 
    };

    cout << solve(grid);
    
    for (auto &&i : grid)
    {
        for (auto &&c : i)
        {
            cout << c << ' ';
        }
        cout << endl;
    }
    

    return 0;
}