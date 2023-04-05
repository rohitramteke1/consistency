#include <bits/stdc++.h>
using namespace std;

class Solution{
    vector<int> v;
    int ans = -1;
public:
    void input(int n) {
        v.resize(n , 0);
        for(int i=0; i<n; ++i)
            v[i] = i+1;
    }
    void solve(int index, int k) {
        if(v.size() == 1) {
            ans = v[0];
            return;
        }
        index = (index + k) % v.size();
        v.erase(v.begin() + index);
        solve(index, k);
    }
    int josephus(int index, int k, int n) {
        input(n);
        solve(0, k);
        return ans;
    }
    
    // without auxillary space   
    // int josephus(int n, int k)
    //     {
    //     if(n==1)
    //         return n;
    //     return (josephus(n-1,k)+k-1)%n+1;
    // }
};

int main()
{
    int n, k;
    cin >> n >> k;
    Solution obj;
    cout << obj.josephus(0, k-1, n) << endl;

    return 0;
}