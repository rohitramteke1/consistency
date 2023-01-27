// 1475. Final Prices With a Special Discount in a Shop
#include <bits/stdc++.h>
using namespace std;

void solve() {
    stack<int> s;
    vector<int> prices = {8,4,6,2,3};
    bool flag;
    int i;
    for (i = 0; i < prices.size(); i++)
    {
        flag = true;
        for (int j = i+1; j < prices.size(); j++)
        {
            if(prices[i] > prices[j]) {
                cout << prices[j] << ' ';
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << -1 << ' ';
        }
    }
}

void func() {
    stack<int> s;
    stack<int> st;
    vector<int> prices = {10,1,1,6};

    int n = prices.size();
    vector<int> ans(n);
    ans[n-1] = prices[n-1];

    s.push(prices[n-1]);
    st = s;

    for (int i = n-2; i >= 0; i--)
    {
        if( !s.empty() ) {
            st.push(prices[i]);
            while (!s.empty() && prices[i] < s.top())
            {
                s.pop();
            }
            if(s.empty()) {
                ans[i] = prices[i];
            }
            else {
                ans[i] = s.top();
            }
            s = st;
            // remove the st stack
        }
    }
    for (auto &&i : ans)
    {
        cout << i << ' ';
    }
}

int main()
{
    // solve();
    func();
    
    return 0;
}