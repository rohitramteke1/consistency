// Link: https://practice.geeksforgeeks.org/problems/count-pair-sum5956/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// HashMap O(N + M) + O(N)
class Solution
{
  public:
    int countPairs(int a[], int b[],  int m, int n, int x) 
    { 
        //code here.
        unordered_map<int, int> mp;
        for (int i=0; i<m; i++) mp[ a[i] ]++;
        
        int res = 0;
        for (int i=0; i<n; i++) {
            int req = x - b[i];
            if ( mp.find(req) != mp.end() ) {
                res += mp[req];
            }
        }
        
        return res;
    } 
};


// Binary Search O(MlogN)
class Solution
{
  public:
    int countPairs(int a[], int b[],  int m, int n, int x) 
    { 
        //code here.
        int res = 0;
    
        for (int i=0; i<m; i++) {
            // we need 
            int req = x - a[i];
            int index = lower_bound(b, b + n, req) - b;
            if( index != n && b[index] == req ) {
                res++;
            }
        }
        
        return res;
    } 
};

// Efficient Solution O(N + M) + O(1)
class Solution
{
  public:
    int countPairs(int a[], int b[],  int m, int n, int x) 
    { 
        int res = 0, sum = 0;
        
        int i = 0, j = n-1;
        
        while (i < m && j >= 0) {
            if (a[i] + b[j] == x)
                res++, i++, j--;
            else if (a[i] + b[j] < x)
                i++;
            else
                j--;
        }
        
        return res;
    } 
};