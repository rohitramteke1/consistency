#include <bits/stdc++.h>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {       
    // Greedy
    sort(costs.begin(), costs.end() );
    int ans = 0;
    for (int i = 0; i < costs.size(); i++)
    {
        if(coins >= costs[i]) {
            ans++;
            coins -= costs[i];
        }
        else ans;
    }
    return ans;
}

int main()
{   
    vector<int> costs = {1,3,2,4,1};
    int coins = 7;
    cout << maxIceCream(costs, coins) << endl;
    
    return 0;
}