// Intersection of Two Arrays II

class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> result;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int i = 0, j = 0;
        
        while ( i < n && j < m ) {
            if (a[i] < b[j]) {
                i++;
            }
            else if (a[i] > b[j]) {
                j++;
            }
            else {
                result.push_back(a[i]);
                i++, j++;
            }
        }
    
        return result;
    }
};