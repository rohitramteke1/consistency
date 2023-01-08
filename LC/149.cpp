#include <bits/stdc++.h>
using namespace std;
int maxPoints(vector<vector<int>>& points) {
    
    int maxSlope = 2;
    if(points.size() == 1) return 1;    
    for (int i = 0; i < points.size(); i++)
    {
        unordered_map<double, int> umap;
        for (int j = 0; j < points.size(); j++)
        {
            if(j != i)
            umap[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
        }

        for (auto [h, count] : umap) {
            maxSlope = max(maxSlope, count + 1);
        }
    }
    return maxSlope;
}
int main()
{
    vector< vector<int> > points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << maxPoints(points) << endl;
    return 0;
}