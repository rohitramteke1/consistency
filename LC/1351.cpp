#include <bits/stdc++.h>
using namespace std;

int binarySearchDescendingForNegative(vector<int>& nums) {
    int low = 0;
    int high = nums.size()-1;
    int mid;
    int ans = -1;
    while(low <= high) {
        // 3, 2, 1, 0, -1, -2
        // 
        mid = low + (high - low) / 2;
        if(mid >= 0 && mid < nums.size() && nums[mid] < 0) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector< vector<int> > grid = {
        // {4,3,2,-1},
        // {3,2,1,-1},
        // {1,1,-1,-2},
        // {-1,-1,-2,-3}
        {5,1,0},
        {-5,-5,-5}
    };

    int neg = 0;
    int n = grid[0].size();
    for(int i=0; i<grid.size(); ++i)
    {
        if(grid[i][n-1] >= 0) continue;
        int x = binarySearchDescendingForNegative(grid[i]);
        if(x == -1) continue;
        neg += n - x;
    }
    
    cout << neg << endl;

    return 0;
}