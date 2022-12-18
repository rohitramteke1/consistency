#include <bits/stdc++.h>
using namespace std;

// BFS O(N^2) + O(1)
int maxProfitBFS(vector<int>& prices) {
    int profit = 0;
    for (int i = 0; i < prices.size(); i++)
        for (int j = i+1; j < prices.size(); j++)
            profit = max(profit, prices[j]-prices[i]);
    
    return profit;
}

// Better O(N) + O(N)
int maxProfitBetter(vector<int>& prices) {
    int profit = 0;
    int size = prices.size();
    int prefix[size];
    // store the last index of prics in prefix
    prefix[size-1] = prices[size-1];

    for (int i = size-1; i > 0; i--)
        prefix[i-1] = max(prefix[i], prices[i-1]);
        
    for (int i = 0; i < prices.size(); i++)
        profit = max(profit, prefix[i]-prices[i]);
    
    return profit;
}

// Optimal O(N) + O(1)
int maxProfitOptimal(vector<int>& prices) {
    int minSoFar = prices[0];
    int profit = 0;
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        minSoFar = min(minSoFar, prices[i]);
        profit = prices[i] - minSoFar;
        maxProfit = max(maxProfit, profit);
    }
    return maxProfit;
}


int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfitBetter(prices) << endl;


    return 0;
}