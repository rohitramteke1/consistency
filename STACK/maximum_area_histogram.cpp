#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
private:
    ll area = 0;
public:
    ll getMaxArea(long long arr[], int n) {
        for (int i = 0; i < n; i++)
        {
            ll min_so_far = INT_MAX;
            for (int j = i; j < n; j++)
            {
                min_so_far = min(min_so_far, arr[j]);
                area = max(area, min_so_far * (j - i + 1));
            }
        }
        return area;
    }
    vector<ll> nearestMinRight(ll arr[], int n) {
        stack<ll> s;
        vector<ll> v(n, n);
        for (int i = n-1; i >=0 ; --i)
        {
            while( !s.empty() && arr[i] <= arr[s.top()] ) {
                s.pop();
            }
            if(!s.empty())
                v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    vector<ll> nearestMinLeft(ll arr[], int n) {
        stack<ll> s;
        vector<ll> v(n, -1);
        for (int i = 0; i < n; i++)
        {
            while(!s.empty() && arr[i] <= arr[s.top()] ) {
                s.pop();
            }
            if(!s.empty())
                v[i] = s.top();
            s.push(i);
        }
        return v;
    }
};

int main()
{
    Solution ob;
    ll arr[] = {6,2,5,4,5,1,6};
    int n = 7;
    // cout << ob.getMaxArea(arr, n) << endl;
    vector<ll> right = ob.nearestMinRight(arr, n);
    vector<ll> left = ob.nearestMinLeft(arr, n);

    vector<ll> width(n, 0);

    for (int i = 0; i < n; i++)
    {
        width[i] = (right[i] - left[i] - 1) * arr[i];
    }
    cout << *max_element( begin(width), end(width) );
    

    return 0;
}