#include <bits/stdc++.h>
using namespace std;
// solve by myself
int solve(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {

    for (int i = 0; i < rocks.size(); i++)
    {
        rocks[i] = (capacity[i] - rocks[i]);
    }

    sort(rocks.begin(), rocks.end());

    int ct = 0;
    for (int i = 0; i < rocks.size(); i++)
    {
        if(rocks[i] - additionalRocks <= 0 && additionalRocks > 0) {
            additionalRocks -= rocks[i];
            ct++;
        }
    }

    return ct;
}


int main()
{
    vector<int> capacity = {2,3,4,5};
    vector<int> rocks = {1,2,4,4};
    int additionalRocks = 2;
    // solve(capacity, rocks, additionalRocks);
    cout << solve(capacity, rocks, additionalRocks) << endl;
    
    return 0;
}