#include <bits/stdc++.h>
using namespace std;

int ans = 0;
// Without DP
int find(int i, bool isStock, int n, vector<int> &prices) {

    if(i >= n) return 0;

    if(isStock == false) {
        int buy = (0 - prices[i]) + find(i + 1, true, n, prices);
        int notBuy = 0 + find(i + 1, false, n, prices);
        ans = max(buy, notBuy);
    }
    else {
        int sell = prices[i] + find(i + 2, false, n, prices);
        int notSell = 0 + find(i + 1, true, n, prices);
        ans = max(sell, notSell);
    }

    return ans;
}

int main()
{
    vector<int> prices = {1,2,3,0,2};
    int n = prices.size();

    cout << find(0,false, n, prices) << endl;
    
    return 0;
}