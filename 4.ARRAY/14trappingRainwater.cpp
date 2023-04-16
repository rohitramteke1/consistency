#include <bits/stdc++.h>
using namespace std;

int trappingRainWater(vector<int> rainwater) {
    int n = rainwater.size();

    vector<int> prefix(n, 0);
    vector<int> suffix(n, 0);

    prefix[0] = rainwater[0];
    suffix[n-1] = rainwater[n-1];
    
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i-1], rainwater[i]);
        suffix[n-1-i] = max(suffix[n-i], rainwater[n-1-i]);
    }
    
    int rain = 0;
    for (int i = 0; i < n; i++)
    {
        rain += min(prefix[i], suffix[i]) - rainwater[i];
    }
    
    return rain;
}

int main()
{
    vector<int> rainwater = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout  << trappingRainWater(rainwater) << endl;
    
    return 0;
}