#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution {
public:
    vector<int> nearestMinRight(int arr[], int n) {
        stack<int> s;
        vector<int> v(n, n);
        for (int i = n-1; i >=0 ; --i)
        {
            while( !s.empty() && arr[i] <= arr[s.top()] ) {
                s.pop();
            }
            if(!s.empty())
                v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    vector<int> nearestMinLeft(int arr[], int n) {
        stack<int> s;
        vector<int> v(n, -1);
        for (int i = 0; i < n; i++)
        {
            while(!s.empty() && arr[i] <= arr[s.top()] ) {
                s.pop();
            }
            if(!s.empty())
                v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    // maximum area of histogram
    int MAH(int arr[], int n) {
        int area = 0;
        vector<int> right = nearestMinRight(arr, n);
        vector<int> left = nearestMinLeft(arr, n);

        for (int i = 0; i < n; i++)
        {
            int curr_area = (right[i] - left[i] - 1) * arr[i];
            area = max(area, curr_area);
        }
        return area;
    }

    int maxArea(int M[MAX][MAX], int n, int m) {
        // O(M) + O(M)
        int arr[m];
        memset(arr, 0, sizeof(arr) );
        
        int max_area = 0;
        
        // O(M + N * M + 2M) ~= O(N * M)
        for(int i=0; i<n; ++i) {
            // create 1D array
            for(int j=0; j<m; ++j) {
                if(M[i][j] == 0)
                    arr[j] = 0;
                else
                    arr[j] += 1;
            }
            int curr_area = MAH(arr, m);
            max_area = max(max_area, curr_area);
        }
        
        return max_area;
    }
};

int main()
{
    Solution ob;
    int n = 4, m = 4;
    int M[n][m] = { {0, 1, 1, 0},
                {1, 1, 1, 1},
                {1, 1, 1, 1},
                {1, 1, 0, 0} };
    cout << ob.maxArea(M, n, m) << endl;

    return 0;
}