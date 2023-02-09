// sort the array by parity
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &v) {
    int n = v.size();
    vector<int> res(n, 0);
    int p = 0;
    int q = n-1;
    for (int i = 0; i < n; ++i)
    {
        if(v[i] & 1) 
            res[q--] = v[i];
        else 
            res[p++] = v[i];
    }
    return res;
}

int main()
{
    vector<int> v = {3,1,2,4};
    vector<int> res = solve(v);

    for (auto &&i : res)
        cout << i << ' ';

    return 0;
}