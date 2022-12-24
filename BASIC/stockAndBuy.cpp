#include <bits/stdc++.h>
using namespace std;
// best time to buy and sell stock

int optimal(int prices[], int n) {
    int minSoFar = prices[0];
    int profit = 0;
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        minSoFar = min(minSoFar, prices[i]);
        profit = prices[i] - minSoFar;
        maxProfit = max(maxProfit, profit);
    }
    return maxProfit;
}

int main()
{
    int prices[] = {7,1,5,3,6,4};
    int n = sizeof(prices)/sizeof(prices[0]);
    int prefix[n];

    prefix[n-1] = prices[n-1];
    for (int i = n - 2; i >= 0; i--)
    {
        prefix[i] = max(prices[i], prefix[i+1]);
    }

    int profit = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        profit = max(profit, prefix[i] - prices[i]);
    }
    cout << profit << endl;
    cout << optimal(prices, n) << endl;
    

    return 0;
}