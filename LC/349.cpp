// Intersection of Two Arrays I

class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        
        vector<int> result;
        
        sort( a.begin(), a.end() );
        sort( b.begin(), b.end() );
        
        int m = a.size();
        int n = b.size();
        
        int i = 0, j = 0 ;
        
        while (i < m && j < n) {
            if (i > 0 && a[i] == a[i-1]) {
                ++i;
                continue;
            }
            if (a[i] < b[j])
                i++;
            else if (a[i] > b[j])
                j++;
            else {
                result.push_back(a[i]);
                i++, j++;
            }
        }
        
        return result;
    }
};