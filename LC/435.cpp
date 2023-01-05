#include <bits/stdc++.h>
using namespace std;


inline bool comp(vector<int> &v1, vector<int> &v2) {
    return v1[1] < v2[1];
}

int eraseOverlapIntervals(vector< vector<int> > & intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    
    int ans = 0;
    vector<int> prev = intervals[0];
    vector<int> curr;
    short start = 0;
    short end = 1;
    for (int i = 1; i < intervals.size(); i++)
    {
        // 0 1 2 3 4 5 6 7 8 9 
        // prev[end] > curr[start] -=> overlapping
        //   1 2 
        //     2 3 
        //   1   3 
        //       3 4
              
        // // 1 2
        // // 2 3
        // // 1 3
        // // 3 4 
        curr = intervals[i];
        if(prev[end] > curr[start]) {
            ans++;
        }
        else {
            prev = curr;
        }
    }
    
    return ans;
}

int main()
{
    // vector< vector<int> > intervals = {{1,2},{2,3},{3,4},{1,3}};
    vector< vector<int> > intervals = {{1,100},{11,22},{1,11},{2,12}};
    cout << eraseOverlapIntervals(intervals) << endl;
    
    return 0;
}