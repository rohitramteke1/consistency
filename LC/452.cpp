#include <bits/stdc++.h>
using namespace std;

// Sorting, based on 2nd column
inline bool comp(vector<int> &v1, vector<int> &v2) {
    return v1[1] < v2[1];
}

int findMinArrowShots(vector<vector<int>>& points) {
    int arrows = 1;
    sort(points.begin(), points.end(), comp);
    int x = points[0][1];
    for (int i = 0; i < points.size(); i++)
    {
        if(x >= points[i][0] && x <= points[i][1]) continue;
        else {
            arrows++;
            x = points[i][1];
        }
    }

    return arrows;
}

int main()
{
    vector< vector<int> > points = {{1,2},{3,4},{5,6},{7,8}};
    cout << findMinArrowShots(points) << endl;
    
    return 0;
}