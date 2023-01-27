// 57.Merge intervals
#include <bits/stdc++.h>
using namespace std;

// brute force
vector< vector<int> > insertInterval(vector<vector < int>> &intervals, vector< int > &newInterval) {
    vector < vector<int> > result;
    int i = 0;

    while (i < intervals.size() )
    {
        if(intervals[i][1] < newInterval[0]) {
            i++;
        } else if(intervals[i][0] > newInterval[1]) {
            intervals.insert(intervals.begin() + i, newInterval);
            return intervals;
        } else {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            intervals.erase(intervals.begin() + i);
        }
    }

    intervals.emplace_back(newInterval);
    return intervals;
}

int main()
{
    vector< vector<int> > intervals = {{1,3},{6,9}}; 
    vector< int > newInterval = {2,5};

    vector< vector<int> > ans = insertInterval(intervals, newInterval);

    for (auto &&i : ans)
    {
        cout << i[0] << ' ' << i[1] << endl;
    }
    
    
    return 0;
}