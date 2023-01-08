#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0;
    int totalCost = 0;
    int currCost = 0;
    int index = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        totalGas += gas[i];
        totalCost += cost[i];
        currCost += gas[i] - cost[i];
        if(currCost < 0) {
            currCost = 0;
            index = i + 1;
        }
    }
    if(totalGas < totalCost) return -1;
    return index; 
}

int solve(vector<int>& gas, vector<int>& cost) {
    int i,j;
    int n = gas.size();
    for (i = 0; i < n; i++)
    {
        if(gas[i] < cost[i]) continue;
        int currCost = gas[i] - cost[i];
        j = (i + 1) % n;
        while(j != i) {
            currCost += gas[j];
            if(currCost < cost[j]) break;
            currCost -= cost[j];
            j = (j + 1) % n;
        }
        if(j == i) return j;
    }
    return -1;
}

int main()
{
    fast_io;
    // vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    vector<int> gas = { 87, 40, 71, 79, 2, 3, 93, 57, 81, 42, 90, 20, 30 };
    vector<int> cost = { 27, 95, 96, 35, 68, 98, 18, 53, 2, 87, 66, 45, 41 };

    cout << canCompleteCircuit(gas, cost) << endl;
    cout << solve(gas, cost) << endl;
    
    return 0;
}