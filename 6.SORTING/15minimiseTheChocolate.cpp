class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort( begin(a), begin(a) + n );
        
        int minChocolate = INT_MAX;
        
        for (int i=0; i<n-m+1; i++) {
            int mn = a[m - 1 + i] - a[i];
            minChocolate = min(mn, minChocolate);
        }
        
        return minChocolate;
    }
};